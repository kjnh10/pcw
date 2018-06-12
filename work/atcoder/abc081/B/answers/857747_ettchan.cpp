#include<bits/stdc++.h>
using namespace std;
const long long INF = 123456789;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <string> vs;
typedef vector <char> vc;
typedef list <ll> lst;

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

#define Endl endl

/*--------------------template--------------------*/

int main() {
    cin >> n;
    vi v(n), va;
    REP(i,n) {
        cin >> v[i];
        cnt = 0;
        while(v[i]%2==0){
            v[i] /= 2;
            cnt++;
        }
        va.push_back(cnt);
    }
    sort(ALL(va));

    cout << va[0] << endl;
    
}