// g++ macro.cpp -std=c++14
#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;

#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define WFA(d,v) REP(k,v)REP(i,v)REP(j,v)d[i][j]=min(d[i][j],d[i][k]+d[k][j])

#define SCOUT(x) cout<<(x)<<" "
#define ENDL cout<<endl

#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECIN2(x,y) REP(i,x.size())cin>>x[i]>>y[i]
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl

#define ALL(obj) (obj).begin(),(obj).end()

#define EXIST(n,x) (find(ALL(n),x)!=n.end())
#define UNIQUE(obj) sort(ALL( obj )); obj.erase(unique(ALL(obj)),obj.end())
#define COUT(x) cout<<(x)<<endl
void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail){
    cin>>head;
    CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision; // cpp_int

#define P pair<int,int>
#define V vector<int>
#define M map<int,int>
#define S set<int>
#define L list<int>

#define pb(a) push_back(a)
#define mp make_pair


int main(){
    CIN(x,a,b);
    COUT((x-a)%b);


    return 0;
}
