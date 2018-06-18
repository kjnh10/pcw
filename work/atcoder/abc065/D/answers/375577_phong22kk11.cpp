#include <bits/stdc++.h>
using namespace std;

#define maxn 100002
#define FOR(i, l, r) for (int i=l; i<=r; ++i)
#define FORD(i, r, l) for (int i=r; i>=l; --i)
#define REP(i, r) for (int i=0; i<(int)r; ++i)
#define REPD(i, r) for (int i=(int)r-1; i>=0; --i)
#define fi first
#define se second
#define mk make_pair
#define nil NULL
#define y0 y902
#define y1 y232
#define x0 x92
#define x1 x899
#define next asdfa
#define sz size
#define Debug(X) {cerr << #X << " = " << X << '\n';}
#define PR(A, n) {cerr << #A << " = "; FOR(i, 1, n) cerr << A[i] << ' '; cerr << '\n';}
#define PR0(A, n) {cerr << #A << " = "; REP(i, n) cerr << A[i] << ' '; cerr << '\n';}
typedef long long ll;
typedef double db;
typedef pair<db, db> dd;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 1e9;
template<class T> int getbit(T x, int pos) {return (x>>(pos-1)) & 1;}
template<class T> void turn_on(T &x, int pos) {x = x | ((T)1<<(pos-1));}
template<class T> void turn_off(T &x, int pos) {x = x & ~((T)1<<(pos-1));}
template<class T> T sqr(T a) {return a*a;}

struct edge {
    int u, v, w;
    edge () {}
    edge(int a, int b, int c) {
        u = a; v = b; w = c;
    }
};
struct point {
    int x, y, id;
} a[maxn];
int n, lab[maxn];
ll res;
vector<edge> e;

bool cmp1(point a, point b) {return a.x<b.x;}
bool cmp2(point a, point b) {return a.y<b.y;}
bool cmp3(edge a, edge b) {return a.w<b.w;}

int findset(int u) {return lab[u]<=0 ? u : lab[u]=findset(lab[u]);}
void uni(int s, int t) {
    if (lab[s]<lab[t]) lab[t] = s;
    else if (lab[s]>lab[t]) lab[s] = t;
    else {lab[t] = s; lab[s]--;}
}

void process(edge e) {
    int s = findset(e.u), t = findset(e.v);
    if (s==t) return;
    uni(s, t);
    res += (ll)e.w;
}

int main() {
    //freopen("build.inp", "r", stdin);
    //freopen("", "w", stdout);
    //ios::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
    }
    sort(a+1, a+n+1, cmp1);
    FOR(i, 1, n-1) {
        e.push_back(edge(a[i].id, a[i+1].id, a[i+1].x-a[i].x));
    }
    sort(a+1, a+n+1, cmp2);
    FOR(i, 1, n-1) {
        e.push_back(edge(a[i].id, a[i+1].id, a[i+1].y-a[i].y));
    }
    sort(e.begin(), e.end(), cmp3);
    REP(i, e.sz())
        process(e[i]);
    printf("%I64d", res);
}

