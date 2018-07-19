/*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds

#define eps 1e-11
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 337

using namespace std;

const int INF = 1e9;
const int N = 500031;

int n, m;
string st;
int l[N], r[N];
int s1[N], s2[N];

int dp[3050][3050];

string solve(string st, int flag)
{
	for (int i = 1; i <=m; i++)
	{
		int a, b;
		a = l[i] - 1;
		b = r[i];
		sort(st.begin() + a, st.begin() + b);
		if (flag)
			reverse(st.begin() + a, st.begin() + b);
	}
	return st;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> n >> m;
	cin >> st;
	
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
	}

	string st1 = solve(st,0);
	string st2 = solve(st,1);
	
	for (int i = 0; i < st1.size(); i++)
	{
		s1[i + 1] = s1[i] + st1[i] - 48;
		s2[i + 1] = s2[i] + st2[i] - 48;
	}

	//cout << st1 << " " << st2 << endl;
	
	dp[0][0] = 1;
	for (int i = 0; i < st.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int ad = 0; ad <= 1; ad++)
			{
				if (j + ad<s1[i + 1] || j + ad>s2[i + 1])
					continue;
				dp[i + 1][j + ad] += dp[i][j];
				dp[i + 1][j + ad] %= bs;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= st.size(); i++)
	{
		ans = ans + dp[st.size()][i];
		ans %= bs;
	}
	cout << ans << endl;

	cin.get(); cin.get();
	return 0;
}