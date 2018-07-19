/*
There was a time, looking through myself
Wanting to pretend
If I escaped, I could fill myself
I don't think you can
Been far and wide
But that hole inside
Never really leaves
When I went away, what I really left
Left behind was me

It's telling me
To be on my way home
Million miles away
I can't stay

Each passing day, every passing face
Seems like such a blur
I long to be
Home, silently
Lying next to her
Just to get back, by her side is all
All I need to be
Cause I went away
But what I really left
Left behind was me

I need to be
Getting on my way home
A million miles away
Million miles away
I can't take
*/

//#pragma GCC optimize("O3")
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

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 510031;

int n,c,cnt[N];
int ans;

vector<pair<int,int> > block[1000];

int main(){
//	freopen("apache.in","r",stdin);
//	freopen("apache.out","w",stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
//	cin.tie(0);

	cin>>n>>c;
	for (int i=1;i<=n;i++){
		int l,r,id;
		cin>>l>>r>>id;
		block[id].push_back(make_pair(l,r));
	}

	for (int i=1;i<=c;i++){
		sort(block[i].begin(),block[i].end());
		int qr=-1e9;
		int ql=-1e9;
		for (int j=0;j<block[i].size();j++){
			if (block[i][j].first!=qr){
				if (j){
					cnt[ql]++;
					cnt[qr+1]--;
				}
				ql=block[i][j].first;
			}
			qr=block[i][j].second;
		}
		//cout<<ql<<"$"<<qr<<endl;
		if (block[i].size())
			cnt[ql]++,cnt[qr+1]--;
	}

/*	for (int i=1;i<=10;i++){
		cout<<cnt[i]<<" ";
	}
*/
	ans=cnt[0];


	for (int i=1;i<=100000;i++){
		cnt[i]+=cnt[i-1];
		ans=max(ans,cnt[i]);
	}
	cout<<ans<<endl;

//	cin.get(); cin.get();
	return 0;
}
