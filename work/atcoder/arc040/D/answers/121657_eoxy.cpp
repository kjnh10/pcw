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

lli n,r;
char s[101];
lli ans;

int main(){
    cin >> n >> r >> s;
    int i = n-1;
    r--;
    while(s[i] == 'o'){
        if(i == 0){
            cout << 0 << endl;
            return 0;
        }
        i--;
    }
    i-=r;
    ans = max(i,0)+1;

    while(i > 0){
        i--;
        if(s[i] != 'o'){
            i-=r;
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}
