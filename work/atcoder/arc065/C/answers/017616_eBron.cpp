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
const int N = 200031;

string st;
int dp[N];

bool match(int ps, string temp)
{
	if (ps + temp.size() > st.size())
		return false;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != st[ps + i])
			return false;
	}
	return true;
}

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//	freopen("F:/input.txt", "r", stdin);
	//	freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin >> st;
	dp[0] = 1;
	for (int i = 0; i < st.size(); i++)
	{
		if (dp[i] == 0)
			continue;
		if (match(i, "dream"))
			dp[i + 5] = 1;
		if (match(i, "dreamer"))
			dp[i + 7] = 1;
		if (match(i, "erase"))
			dp[i + 5] = 1;
		if (match(i, "eraser"))
			dp[i + 6] = 1;
	}

	if (dp[st.size()])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	cin.get(); cin.get();
	return 0;
}