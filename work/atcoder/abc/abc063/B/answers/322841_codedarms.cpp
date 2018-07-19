#include <iostream>
#include <string.h>
#include <set>
#include <vector>
#include <queue>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
using namespace std;
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,n) for(ll i=1;i<=n;i++)
#define N 1000
#define kr 1000000007
ll binarys(ll low,ll high,ll a[],ll x)
{
    while (high-low>1) {
        ll mid=low+(high-low)/2;
        if(a[mid]>x)
            high=mid;
        else
            low=mid;
    }
    if(a[high]<=x)
        return high;
    else if(a[low]<=x)
        return low;
    else
        return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    string a;
    cin>>a;
    set<char>s;
    rep(i,a.length())
    {
        s.insert(a[i]);
    }
    if(s.size()==a.length())
        cout<<"yes";
    else
        cout<<"no";
}
