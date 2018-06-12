#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
//cout<<setprecision(20)
//const llint mod=987654323;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>void mineq(T& a,U b){if(a>b){a=b;}}
template <class T,class U>void maxeq(T& a,U b){if(a<b){a=b;}}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
int LBI(vector<lldo>&ar,lldo in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
int UBI(vector<lldo>&ar,lldo in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
llint mod;
llint pow(llint a,llint n){//a^n
	llint ans=1;
	for(int h=0;h<30;h++){
		if((1<<h)&n){ans*=a;ans%=mod;}
		a*=a;a%=mod;
	}
	return ans;
}
vector<llint>fla;
vector<llint>gya;
vector<llint>niwa;
vector<llint>niruru;
llint nCr(int n,int r){return ((fla[n]*gya[r])%mod *gya[n-r])%mod;}
int main(void){
	//包除?
	llint n,i,j;cin>>n>>mod;
	fla.res(n+1);gya.res(n+1);niwa.res(n+1);niruru.res(n+1);
	niwa[0]=1;
	for(i=1;i<=n;i++){niwa[i]=niwa[i-1]*2%mod;}
	niruru[0]=2;
	for(i=1;i<=n;i++){niruru[i]=niruru[i-1]*niruru[i-1]%mod;}
	fla[0]=1;
	for(i=1;i<=n;i++){fla[i]=(fla[i-1]*i)%mod;}
	gya[n]=pow(fla[n],mod-2);
	for(i=n;i>=1;i--){gya[i-1]=(gya[i]*i)%mod;}
	vector<vector<llint>>ipai(n+2,vector<llint>(n+2));
	//ピッタリ1杯が0~n個、m分割
	//これはなぜかdpでできる 修行のおかげのエスパー
	ipai[0][0]=1;
	ipai[1][1]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			ipai[i][j]%=mod;
			ipai[i+1][j]+=ipai[i][j]*j;
			ipai[i+1][j+1]+=ipai[i][j];
		}
	}
	//0か1杯 が n1,m+1
	//例 0か1がa種類,b杯->dp[a+1][b+1]
	
	llint ans=0;
	for(i=0;i<=n;i++){//条件を満たさない具材の数
		for(j=0;j<=i;j++){//条件を満たさない を含むラーメンの数
			llint gen=nCr(n,i)*ipai[i+1][j+1];gen%=mod;
			gen*=pow(niwa[n-i],j);gen%=mod;
			gen*=niruru[n-i];gen%=mod;
			//cerr<<"i="<<i<<"j="<<j<<"dp="<<ipai[i+1][j+1]<<endl;
			if(i%2){ans-=gen;ans%=mod;}
			else{ans+=gen;ans%=mod;}
		}
	}
	ans+=mod;ans%=mod;
	cout<<ans<<endl;
	return 0;
}
