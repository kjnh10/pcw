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

int n,m;
long long a[1031],b[1031],c[1031],dp[1031][1031][10];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>m;

	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}

	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			for (int q=0;q<8;q++){
				dp[i][j][q]=-1e18;
			}
		}
	}
	for (int i=0;i<8;i++){
		dp[0][0][i]=0;
	}

	for (int i=0;i<n;i++){
		for (int j=0;j<=m;j++){
			for (int q=0;q<8;q++){
				dp[i+1][j][q]=max(dp[i+1][j][q],dp[i][j][q]);
				// take
				long long here=dp[i][j][q];
				if (q&1)
					here+=a[i+1];
				else
					here-=a[i+1];
				if (q&2)
					here+=b[i+1];
				else
					here-=b[i+1];
				if (q&4)
					here+=c[i+1];
				else
					here-=c[i+1];
				dp[i+1][j+1][q]=max(dp[i+1][j+1][q],here);
			}
		}
	}

	long long res=0;
	for (int i=0;i<8;i++){
		res=max(res,dp[n][m][i]);
	}
	cout<<res<<endl;

//	cin.get(); cin.get();
	return 0;
}
