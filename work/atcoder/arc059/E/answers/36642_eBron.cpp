/*
*/

//#pragma comment(linker, "/STACK:16777216")
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

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 200000;

int n, c, a[N], b[N];

long long dp[1000][1000];
long long P[1000][1000];

long long pw(long long a, long long b)
{
	if (b == 0)
		return 1;
	if (b % 2)
		return a*pw(a, b - 1) % bs;
	return pw(a*a%bs, b / 2);
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	dp[0][0] = 1;

	for (int i = 1; i <= 400; i++)
	{
		for (int j = 0; j <= 400; j++)
		{
			if (j == 0)
				P[i][j] = 1;
			else
				P[i][j] = P[i][j - 1] * i%bs;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int ad = 0; ad <= c; ad++)
		{
			long long val = 0;
			for (int j = a[i + 1]; j <= b[i + 1]; j++)
			{
				val += P[j][ad];// pw(j, ad);
				val %= bs;
			}
			for (int sum = 0; sum <= c; sum++)
			{
				dp[i + 1][sum + ad] += dp[i][sum] * val%bs;
				dp[i + 1][sum + ad] %= bs;
			}
		}
	}

	cout << dp[n][c] << endl;

	cin.get(); cin.get();
	return 0;
}