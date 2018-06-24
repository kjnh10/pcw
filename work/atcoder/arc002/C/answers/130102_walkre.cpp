#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    int n;
    string c;
    cin >> n >> c;

    vector<int> memo(n,inf);
    function<int(int,string,string)> rec=[&](int i,string l,string r){
        if(i==n) return 0;
        if(memo[i]!=inf) return memo[i];
        memo[i]=rec(i+1,l,r)+1;
        if(i+1<n and ((c[i]==l[0] and c[i+1]==l[1]) or (c[i]==r[0] and c[i+1]==r[1]))) memo[i]=min(memo[i],rec(i+2,l,r)+1);
        return memo[i];
    };

    int ans=inf;
    vector<string> ss;
    rep(i,0,4) rep(j,0,4) ss.push_back({"ABXY"[i],"ABXY"[j]});
    rep(i,0,16){
        rep(j,i+1,16){
            fill(memo.begin(),memo.end(),inf);
           ans=min(ans,rec(0,ss[i],ss[j])); 
        }
    }
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
