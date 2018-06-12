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

const int N = 500031;

int a,b,c,d,e,f,reach_w[N],reach_s[N];
int ans;
int ai,aj;

int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin>>a>>b>>c>>d>>e>>f;

	double best_rat=-1e9;

	reach_w[0]=1;
	reach_s[0]=1;

	for (int i=0;i<=3000;i++)
	{
		if (reach_w[i])
		{
			reach_w[i+a]=1;
			reach_w[i+b]=1;
		}
		if (reach_s[i])
		{
			reach_s[i+c]=1;
			reach_s[i+d]=1;
		}
	}

	for (int i=100;i<=f;i++)
	{
		for (int j=0;j+i<=f;j++)
		{
			if (i%100)
				continue;
			if (reach_w[i/100]==0||reach_s[j]==0)
				continue;
			if (j>i/100*e)
				continue;
			if (j*1.0/i>best_rat){
				best_rat=j*1.0/i;
				ai=i;
				aj=j;
			}
		}
	}

	cout<<ai+aj<<" "<<aj<<endl;

	cin.get(); cin.get();
	return 0;
}

