#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{

    ll n,s;
    cin>>n>>s;
    for (ll b = 2; b<=1000000; b++) {
        ll N = n;
        ll sum = 0;
        while(N>0) {
            sum+=N%b;
            N/=b;
        }
        if(sum == s) {
            cout<<b;
            return 0;
        }
    }
    for(ll nb = 100000; nb > 0; nb--) {
        ll ost = s - nb;
        if(ost <0) continue;
        if(ost>n) continue;
        ll A = n-ost;
        if(A%nb != 0) continue;
        if(A/nb <= ost) continue;
        cout<<A/nb;
        return 0;
    }
    if(s==n) cout<<s+1;
    else cout<<-1;
    
    
    
}

