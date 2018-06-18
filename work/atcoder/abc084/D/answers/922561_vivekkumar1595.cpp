#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()

#define SI(n) scanf("%d",&n)
#define PI(n) printf("%d\n",n)
#define SL(n) scanf("%lld",&n)
#define PL(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE
#ifdef TRACE
#define TR(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define TR(...)
#endif
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
typedef long long int 	LL;
typedef long double 	LD;
typedef pair<int,int>   II;
typedef vector<int>     VI;
const int MOD = 1e9 + 7;
const int N = 100011;
int cnt[N];
bool prime[N];

void sieve() {
    for(int i = 2; i < N; ++i)
        prime[i] = 1;
    for(int i = 2; i < N; ++i) {
        if(prime[i])
            for(int j = 2*i; j < N; j += i) {
                prime[j] = 0;
            }
        
    }
}

int main() {
    int q;
    SI(q);
    sieve();
    for(int i = 1; i < N; ++i) {
        if((i&1) && prime[i] && prime[(i + 1)/2])
            cnt[i]++;
        cnt[i] += cnt[i-1];
    }
    while(q--) {
        int l, r;
        SI(l), SI(r);
        PI(cnt[r] - cnt[l-1]);
    }
    return 0;
}