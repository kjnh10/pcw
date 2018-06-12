#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

lli n;
vector<lli> a;
lli ans;

int main(){
    cin >> n;
    a = vector<lli>(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a.begin(),a.end(),greater<lli>());
    for(int i = 0;i < n;i+=2){
        ans += a[i];
    }
    cout << ans << endl;
	return 0;
}
