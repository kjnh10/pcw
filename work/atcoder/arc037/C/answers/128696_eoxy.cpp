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
vector<lli> m;
lli ans = 0;

int main(){
    cin >> n;
    m = vector<lli>(n);
    for(int i = 0;i < n;i++) cin >> m[i];
    for(int i = 0;i < n;i++){
        ans += max(80-m[i],(lli)0);
    }
    cout << ans << endl;
	return 0;
}
