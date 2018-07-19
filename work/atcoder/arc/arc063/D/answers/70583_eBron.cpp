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

#define eps 1e-6
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 350

using namespace std;

const int INF = 1e9;
const int N = 110000;

int n, T, mx, mn, cnt;
int ar[N];
int bst;

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	//freopen("F:/in.txt", "r", stdin);
	//freopen("F:/output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	mn = 1e9;

	cin >> n >> T;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
		if (ar[i] < mn)
		{
			mn = ar[i];
		}
		if (ar[i]>mx)
		{
			mx = ar[i];
		}
		if (ar[i] - mn >= bst)
		{
			if (ar[i] - mn > bst)
				cnt = 0;
			++cnt;
			bst = ar[i] - mn;
		}
	}
	//cout << bst << endl;

	cout << cnt << endl;

	cin.get(); cin.get();
	return 0;
}