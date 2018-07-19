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
const llint mod=1000000007;
const llint big=1.19e18+1;
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
int main(void){
	int n,i;cin>>n;
	if(n==2){cout<<"1 2"<<endl;return 0;}
	if(n==3){cout<<"1 2 3"<<endl;return 0;}
	vector<vector<int>>go(n);
	for(i=0;i<n-1;i++){
		int a,b;cin>>a>>b;a--;b--;
		go[a].pub(b);
		go[b].pub(a);
	}
	vector<int>nozi(n);
	int haza=-1,hazb=-1;
	for(i=0;i<n;i++){
		if(go[i].size()<=1){continue;}
		int g=0;
		for(auto it:go[i]){
			if(go[it].size()>1){g++;}
		}
		nozi[i]=g;
		if(g>2){cout<<"-1\n";return 0;}
		if(g==0){haza=i;hazb=i;}
		if(g==1){
			if(haza==-1){haza=i;}
			else{hazb=i;}
		}
	}
	vector<int>ansab;
	ansab.pub(1);
	int gen=haza,mae=-1;
	while(-1){
		int kazu=go[gen].size();
		kazu-=2;
		int ne=ansab.size()+1;
		while(kazu--){
			int nf=ansab.size()+2;
			ansab.pub(nf);
		}
		ansab.pub(ne);
		if(gen==hazb){break;}
		for(auto it:go[gen]){
			if(it!=mae&&go[it].size()>1){mae=gen;gen=it;break;}
		}
	}
	ansab.pub(n);
	
	
	vector<int>ansba;
	ansba.pub(1);
	gen=hazb,mae=-1;
	while(-1){
		int kazu=go[gen].size();
		kazu-=2;
		int ne=ansba.size()+1;
		while(kazu--){
			int nf=ansba.size()+2;
			ansba.pub(nf);
		}
		ansba.pub(ne);
		if(gen==haza){break;}
		for(auto it:go[gen]){
			if(it!=mae&&go[it].size()>1){mae=gen;gen=it;break;}
		}
	}
	ansba.pub(n);
	if(ansab>ansba){ansab=move(ansba);}
	for(auto it:ansab){cout<<it<<" ";}cout<<endl;
	return 0;
}