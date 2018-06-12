#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
#define ALL(c) c.begin(),c.end()
#define PB push_back
#define S second
#define F first
using namespace std;
typedef long long LL;
typedef int ut;
typedef vector<ut> VI;
typedef pair<ut,ut> pr;
typedef vector<pr> Vpr;
typedef ut quut;
typedef priority_queue<quut,vector<quut>,greater<quut> > PQ;
const int INF=1<<30;
const int SIZE=5+1e5;
const int FSIZE=6;
int DP[SIZE];
int alpha[30];
int main(){
	string s;
	cin >> s;
	REP(i,s.size()){
		alpha[s[i]-'a']++;
	}
	int twin=0,one=0;
	REP(i,'z'-'a'+1){
		one+=alpha[i]&1;
		twin+=alpha[i]/2;
	}
	if(one)
		cout << twin/one*2+1 << endl;
	else
		cout << twin*2 << endl; 
	return 0;
}