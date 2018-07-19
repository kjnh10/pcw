#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(void){
    int n;
    cin >> n;
    VI a(n);
    REP(i,n) scanf("%d",&a[i]);

    ll ans = 1, x = 1;
    FOR(i,1,n-1){
        if (a[i]>a[i-1]){
            x++;
        }else{
            x = 1;
        }
        ans += x;
    }

    printf("%lld\n",ans);
    
    return 0;
}