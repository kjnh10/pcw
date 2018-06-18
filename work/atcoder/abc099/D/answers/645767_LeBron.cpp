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

int n,c,D[531][531],cnt[531][531];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>c;

	for (int i=1;i<=c;i++){
		for (int j=1;j<=c;j++){
			cin>>D[i][j];
		}
	}

	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int v;
			cin>>v;
			cnt[(i+j)%3][v]++;
		}
	}

	long long ans=1e9;

	for (int c1=1;c1<=c;c1++){
		for (int c2=1;c2<=c;c2++){
			for (int c3=1;c3<=c;c3++){
				if (c1==c2||c1==c3||c2==c3)
					continue;
				long long here=0;
				for (int q=1;q<=c;q++){
					here+=cnt[1][q]*D[q][c1]+cnt[2][q]*D[q][c2]+cnt[0][q]*D[q][c3];
				}
				ans=min(ans,here);
			}
		}
	}

	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}
