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

lli h,w;
vector<string> s;

bool solve(int i,int j){
    static bool dp[101][101];
    static bool vs[101][101];
    if(vs[i][j]) return dp[i][j];
    vs[i][j] = true;
    if(i >= h || j >= w || s[i][j] == '#') return dp[i][j] = true;
    if(solve(i+1,j) == false) return dp[i][j] = true;
    if(solve(i,j+1) == false) return dp[i][j] = true;
    if(solve(i+1,j+1) == false) return dp[i][j] = true;
    else return dp[i][j] = false;
}


int main(){
    cin >> h >> w;
    s = vector<string>(h);
    for(int i = 0;i < h;i++) cin >> s[i];
    cout << (solve(0,0) ? "First" : "Second")<< endl;
	return 0;
}
