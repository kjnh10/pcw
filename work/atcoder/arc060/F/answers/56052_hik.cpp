// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
    int c=0;
    while ( *s!=',' || c!=0 ) {
        if ( *s=='(' || *s=='[' || *s=='{' ) c++;
        if ( *s==')' || *s==']' || *s=='}' ) c--;
        cerr<<*s++;
    }
    cerr<<"="<<head<<", ";
    _dump(s+1,tail...);
}

#define dump(...) do { \
    fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
    _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0)

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
    s<<"[";
    for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
    s<<"]";
    return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( long long &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}

#ifdef SHIK
#define FILEIO(...)
#else
#define FILEIO(name) do {\
    freopen(name ".in","r",stdin); \
    freopen(name ".out","w",stdout); \
} while (0)
#endif

// }}}

const int N=5e5+10;
const int MOD=1000000007;

struct StrHashRange {
    const static int P=131;
    const static LL MOD=1000000000000000003;
    vector<LL> pw,sh;
    int n;
    void init( const char *s ) {
        n=strlen(s);
        pw.resize(n+1);
        sh.resize(n+1);
        pw[0]=1;
        for ( int i=0; i<n; i++ ) pw[i+1]=(__int128_t)pw[i]*P%MOD;
        for ( int i=0; i<n; i++ ) sh[i+1]=((__int128_t)sh[i]*P+s[i])%MOD;
    }
    LL operator()( int l, int r ) {
        LL h=sh[r+1]-(__int128_t)sh[l]*pw[r-l+1]%MOD;
        if ( h<0 ) h+=MOD;
        return h;
    }
} h;

char s[N];
bool dpl[N],dpr[N];
int main() {
    R(s);
    int n=strlen(s);
    bool same=1;
    REP(i,n) if ( s[i]!=s[0] ) same=0;
    if ( same ) {
        W(n);
        W(1);
        return 0;
    }
    h.init(s);
    REP1(i,1,n) {
        for ( int j=i; j+i<=n && h(0,i-1)==h(j,j+i-1); j+=i ) dpl[j+i-1]=1;
        for ( int j=n-i-i; j>=0 && h(n-i,n-1)==h(j,j+i-1); j-=i ) dpr[j]=1;
    }
    if ( !dpl[n-1] ) {
        W(1);
        W(1);
        return 0;
    }
    int cnt=0;
    REP(i,n-1) if ( !dpl[i] && !dpr[i+1] ) cnt++;
    W(2);
    W(cnt);
    return 0;
}
