#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef int Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<double,int,double> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf=sizeof(Def)==sizeof(long long)?2e18:1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main(){
	int n,m;
	cin>>n>>m;
	int a;cin>>a;
	vvi in(n,vi(m));
	int I=0,J=0;
	rep(i,a){
		int t;cin>>t;
		while(t){
			in[I][J]=i+1;
			if(I%2==0){
				J++;
				if(J==m){
					J--;
					I++;
				}
			}else{
				J--;
				if(J==-1){
					J++;
					I++;
				}
			}
			t--;
		}
	}
	rep(i,n){
		rep(j,m){
			if(j)cout<<" ";
			cout<<in[i][j];
		}
		cout<<endl;
	}
}







