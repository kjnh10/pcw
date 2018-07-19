/*
*/

#pragma GCC optimize("O3")
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
#define ends asdgahhfdsfshdshfd

#define eps 1e-11
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 100031;

int n;
int D[500][500];
int m,r;
vector<int> order;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>n>>m>>r;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			D[i][j]=1e9;
		}
	}

	for (int i=1;i<=r;i++)
	{
		int val;
		cin>>val;
		order.push_back(val);
	}

	for (int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		D[a][b]=min(D[a][b],c);
		D[b][a]=min(D[b][a],c);
	}

	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
			}
		}
	}

	int ans=1e9;

	sort(order.begin(),order.end());
	do{
		int here=0;
		for (int i=1;i<order.size();i++)
		{
			here+=D[order[i-1]][order[i]];
		}
		ans=min(ans,here);
	}while (next_permutation(order.begin(),order.end()));

	cout<<ans<<endl;

	cin.get(); cin.get();
	return 0;
}
