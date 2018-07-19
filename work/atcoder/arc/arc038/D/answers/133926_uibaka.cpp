#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(vector<string> const& v, int x, int y, vector<vector<int>>& dp) {
    if(y >= v.size() || x >= v[0].size()) {
        return 1;
    }
    if(dp[y][x] != -1) {
        return dp[y][x];
    }
    if(v[y][x] == '#') {
        return dp[y][x] = 1;
    }
    int res = 0;
    res = solve(v, x+1, y, dp) == 0 || solve(v, x, y+1, dp) == 0 || solve(v, x+1, y+1, dp) == 0;
    return dp[y][x] = res;
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> v(H);
    for(int i=0; i<H; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> dp(H, vector<int>(W, -1));
    if(solve(v, 0, 0, dp) == 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}
