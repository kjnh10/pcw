#include <bits/stdc++.h>
using namespace std;

const int len = 1000;
int n, w;
pair < int, int > f[len];

map < long long, long long > dp;

int main(){
    cin >> n >> w;
    for(int i = 0;i < n;i++)
        cin >> f[i].first >> f[i].second;
    dp[0] = 0;
    for(int i = 0;i < n;i++){
        for(auto j = dp.rbegin();j != dp.rend();j++){
            if(dp.count(f[i].first + j->first) == 0 && f[i].first + j->first <= w){
                dp[f[i].first + j->first] = j->second + f[i].second;
            }else
            if(dp.count(f[i].first + j->first) != 0 && f[i].first + j->first <= w){
                dp[f[i].first + j->first] = max(dp[f[i].first + j->first], j->second + f[i].second);
            }
        }
    }
    long long res = 0;
    for(auto i = dp.begin();i != dp.end();i++){
        res = max(res, i->second);
    }
    cout << res;
}