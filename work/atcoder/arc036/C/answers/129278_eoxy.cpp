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

lli n,k;
vector<lli> t;

int main(){
    cin >> n >> k;
    t = vector<lli>(n);
    for(int i = 0;i < n;i++) cin >> t[i];
    for(int i = 2;i < n;i++){
        if(t[i-2]+t[i-1]+t[i] < k){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
	return 0;
}
