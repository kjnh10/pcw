#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

using llong = long long;
using ld = long double;
using ii = pair<int, int>;
using ull = unsigned long long;
using pll = pair<llong, llong>;
using vi = vector<int>;


#define endl "\n"
#define fi first
#define se second
#define left LEVO
#define right PRAVO
#define time CHAS
#define all(a) (a).begin(), (a).end()
#define prev PAPEREDNIKXD
#define next NASTUPNIKXD
#define pb push_back
#define deb cout<<"CHECK\n";
#define last(a) (a)[(a).size()-1]

#define elif else if
#define cclear cout<<flush;
#define fclear fflush(stdout);
#define x_files freopen("exam.in","r",stdin);freopen("exam.out","w",stdout);
#define kchay ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
const llong over999 = 1e14;
const ld eps = 1e-9;
const int base = 1000*1000;
const ld Pi = acos(-1);
const llong md = 1e9+7;
const llong ya = 0;

/*.st*/

llong n, x, cnt, ff;
int main() {
    kchay;   
    //x_files;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x && x%4==0)cnt++; 
            elif(x && x%2==0)ff++;
    }
    ff -= ff&1;
    if(cnt >= (n-ff)/2)cout << "Yes"; else cout << "No";
    cout << endl;
    return 0;
}