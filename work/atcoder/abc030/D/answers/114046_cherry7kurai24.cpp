#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define all(v) ALL(v)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
#define CININIT cin.tie(0),ios::sync_with_stdio(false)
struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

int digitMod(string s,int md){
    int ret = 0;
    for(int i=0;i<s.size();i++){
        ret = (ret*10 + s[i] - '0') % md;
    }
    return ret;
}

int main(){
    int N,a;
    cin>>N>>a;
    a--;
    string k;
    cin>>k;
    vector<int> b(N);
    rep(i,N){
        cin>>b[i];
        b[i]--;
    }

    vector<bool> used(N,false);
    vector<int> vis;
    int now=a;
    int len=0;
    while(!used[now]){
        used[now]=true;
        vis.push_back(now);
        len++;
        now = b[now];
    }
    int T=0;
    for(int i=0;i<len;i++){
        if(vis[i]==now) break;
        T++;
    }
    int C=len-T;

    int KmodC = digitMod(k,C);
    if(KmodC < T){
        while(KmodC < T){
            KmodC += C;
        }
    }

    if(k.size()<7){
        KmodC = stoi(k);
    }

    for(int i=0;i<KmodC;i++){
        a = b[a];
    }

    cout << a+1 << endl;
}
