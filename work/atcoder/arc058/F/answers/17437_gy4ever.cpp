#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int n, k;
bool dp[2002][10001];
bool good[2002][10001];
string s[2002];

vector <int> which;
vector <int> pos;

vector <int> next_which;
vector <int> next_pos;


char getBest()
{
	char ret = 'z';
	for(int i = 0; i < which.size(); i++)
	{
		ret = min(ret, s[which[i]][pos[i]]);
	}
	return ret;
}

void updateNext(char c, int remain)
{
	next_which.clear();
	next_pos.clear();
	int firstFinish = n+1;
	int rate = which.size() / 4000;
	for(int i = 0; i < which.size(); i += (rate + 1))
		if(s[which[i]][pos[i]] == c)
		{
			if(pos[i] == s[which[i]].length()-1)
				firstFinish = min(firstFinish, which[i]);
			else
			{
				next_which.push_back(which[i]);
				next_pos.push_back(pos[i]+1);
			}
		}
	for(int i = firstFinish + 1; i <= n; i++)
		if(good[i][remain])
		{
			next_which.push_back(i);
			next_pos.push_back(0);
		}
	which = next_which;
	pos = next_pos;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	memset(dp, 0, sizeof(dp));
	dp[n+1][0] = true;
	for(int i = n; i >= 1; i--)
		for(int j = 0; j <= k; j++)
		{
			if(dp[i+1][j] == true)
				dp[i][j] = true;
			if(j - (int)s[i].length() >= 0 && dp[i+1][j-(int)s[i].length()])
				dp[i][j] = true;
		}
	memset(good, false, sizeof(good));
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			if(s[i].length() <= j && dp[i+1][j - (int)s[i].length()])
				good[i][j] = true;

	int remain = k;
	for(int i = 1; i <= n; i++)
		if(good[i][remain])
		{
			which.push_back(i);
			pos.push_back(0);
		}
	string ret;
	for(int i = 1; i <= k; i++)
	{
		char c = getBest();
		remain --;
		updateNext(c, remain);
		ret += c;
	}
	cout << ret << endl;
	return 0;
}
