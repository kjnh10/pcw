#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<52;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

bool uruu(int y){
	return y%400==0||(y%100!=0&&y%4==0);
}

int y,m,d;

int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	char c;
	cin>>y>>c>>m>>c>>d;
	while(y%m!=0||y/m%d!=0){
		d++;
		if(((uruu(y)&&m==2)?M[1]+1:M[m-1])<d){
			d=1;
			m++;
			if(m==13){
				m=1;
				y++;
			}
		}
	}
	cout<<y<<c;
	if(m<10) cout<<'0';
	cout<<m<<c;
	if(d<10) cout<<'0';
	cout<<d<<endl;
}