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

lli takahashi;
lli aoki;
char s[101];
lli n;

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> s;
        for(int j = 0;j < n;j++){
            if(s[j] == 'R') takahashi++;
            else if(s[j] == 'B') aoki++;
        }
    }
    if(takahashi > aoki) cout << "TAKAHASHI" << endl;
    else if(takahashi < aoki) cout << "AOKI" << endl;
    else cout << "DRAW" << endl;

	return 0;
}
