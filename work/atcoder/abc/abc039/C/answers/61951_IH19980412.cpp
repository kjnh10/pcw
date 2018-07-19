#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod 1000000007
int main(){
	string s[7];
	s[0] = "WBWBWWBWBWBW";
	s[1] = "WBWWBWBWBWWB";
	s[2] = "WWBWBWBWWBWB";
	s[3] = "WBWBWBWWBWBW";
	s[4] = "WBWBWWBWBWWB";
	s[5] = "WBWWBWBWWBWB";
	s[6] = "WWBWBWWBWBWB";
for(int i=0;i<7;i++) for(int j=i+1;j<7;j++) if(s[i]  == s[j]) assert(0);
	string t[7];
	t[0] = "Do"; t[1] = "Re"; t[2] = "Mi";
	t[3] = "Fa"; t[4] = "So"; t[5] = "La";
	t[6] = "Si";
	string x; cin >> x;
	for(int i=0;i<7;i++){
		for(int j=0;j<12;j++){
			if(x[j] != s[i][j]) goto nxt;
		}
		cout << t[i] << endl; return 0; nxt:;
	}
}