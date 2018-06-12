#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n;
    cin>>n;
    long long int ans = 1;
    for(int i=1;i<=n;i++)
    {
        ans = (ans%MOD)*(i%MOD);
        ans = ans%MOD;
    }
    cout<<ans<<endl;
    return 0;
}