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
vector<lli> h;
vector<lli> valley;

int main(){
    cin >> n;
    h = vector<lli>(n);
    for(int i = 0;i < n;i++) cin >> h[i];
    lli p = 0;
    for(int i = 1;i < n-1;i++){
        if(h[i] < h[i-1] && h[i] < h[i+1]){
            valley.push_back(i-p);
            p = i;
        }
    }
    valley.push_back(n-1 - p);
    cout << *max_element(valley.begin(),valley.end())+1 << endl;
	return 0;
}
