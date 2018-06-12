#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
double p;
double cal(double x){
	return x+pow(0.5,x/1.5)*p;
}
int main()
{
	cin>>p;
	double lo=0.0,hi=100;
	rep(i,300){
		double m1=(lo*2+hi)/3,m2=(lo+hi*2)/3;
		if(cal(m1)<cal(m2)) hi=m2;else lo=m1;
	}
	printf("%.12f\n",cal(lo));
}
