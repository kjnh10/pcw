#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
const ll INF=1e9+7;
const ll N = 200002;
string s;
string ans[5];
set<string> se;
ll k;

void cange(string q){
	if(se.count(q)==1)return;
	se.insert(q);
	if(q<ans[0]){
		ans[4]=ans[3];
		ans[3]=ans[2];
		ans[2]=ans[1];
		ans[1]=ans[0];
		ans[0]=q;
	}else if(ans[1]>q){
		ans[4]=ans[3];
		ans[3]=ans[2];
		ans[2]=ans[1];
		ans[1]=q;
	}else if(ans[2]>q){
		ans[4]=ans[3];
		ans[3]=ans[2];
		ans[2]=q;
	}else if(ans[3]>q){
		ans[4]=ans[3];
		ans[3]=q;
	}else if(ans[4]>q){
		ans[4]=q;
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>k;
	FOR(i,0,5){
		ans[i]="zzzzz";
	}
	FOR(i,0,s.size()){
		FOR(j,1,6){
			if(i+j<=s.size()){
				cange(s.substr(i,j));
			}
		}
	}
	cout<<ans[k-1]<<endl;
	return 0;
}