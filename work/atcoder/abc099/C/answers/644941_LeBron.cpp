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
#define prev asdgSHJsfgsdfhdsh

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 1200031;

int dp[N];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	for (int i=0;i<=1000000;i++){
		dp[i]=1e9;
	}
	dp[0]=0;
	for (int i=0;i<1000000;i++){
		dp[i+1]=min(dp[i+1],dp[i]+1);
		for (int j=6;j+i<=1000000;j*=6){
			dp[i+j]=min(dp[i+j],dp[i]+1);
		}
		for (int j=9;j+i<=1000000;j*=9){
			dp[i+j]=min(dp[i+j],dp[i]+1);
		}
	}

	int n;
	cin>>n;
	cout<<dp[n]<<endl;

//	cin.get(); cin.get();
	return 0;
}
