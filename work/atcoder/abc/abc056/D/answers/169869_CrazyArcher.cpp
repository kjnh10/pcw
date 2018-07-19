//
//  main.cpp
//  D
//
//  Created by 黄宇凡 on 2017/3/18.
//  Copyright © 2017年 黄宇凡. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5005;

int n,k;

int a[maxn];

bool pre[maxn][maxn];
long long suf[maxn][maxn];



int main(int argc, const char * argv[]) {
    cin >> n >> k;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",a + i);
        sum += a[i];
    }
    memset(pre,false,sizeof(pre));
    memset(suf,false,sizeof(suf));
    pre[0][0] = true;
    suf[n + 1][0] = 1;
    for(int i = 1;i <= n;i++){
        //pre[i][j] = pre[i - 1][j];
        for(int j = k;j >= 0;j--){
            pre[i][j] |= pre[i - 1][j];
            if(j >= a[i])pre[i][j] |= pre[i - 1][j - a[i]];
        }
    }
    for(int i = n;i >= 1;i--){
        for(int j = k;j >= 0;j--){
            suf[i][j] = suf[i + 1][j];
            if(j >= a[i]) suf[i][j] |= suf[i + 1][j - a[i]];
        }
    }
    for(int i = n + 1;i >= 1;i--){
        for(int j = 0;j <= k;j++){
            if(j == 0) continue;
            suf[i][j] += suf[i][j - 1];
        }
    }
    /*
    for(int i = 0;i <= n + 1;i++){
        for(int j = 0;j <= k;j++){
            if(j == 0) continue;
            else {pre[i][j] |= pre[i][j - 1];suf[i][j] |= suf[i][j - 1];}
        }
    }*/
    int ans = n;
    for(int i = 1;i <= n;i++){
        bool flag = false;
        //bool f = false;
        for(int j = 0;j <= k - 1;j++){
            if(pre[i - 1][j] && ((suf[i + 1][k - 1 - j] - ((k - 1 - a[i] - j) >= 0 ? suf[i + 1][k - 1 - a[i] - j] : 0)) > 0)) {flag = true;}
               // cout << suf[i + 1][k - 1 - j] << endl;
               // cout << "!" << suf[i + 1][k - 1 - a[i] - j] << endl;
               // cout << i << " " << "keyi" << j << endl;}
        }
        //cout << flag << endl;
        //cout << flag << " " << f << endl;
        if(flag) ans--;
       // if(!f) ans++;
    }
    //if(sum < (long long)k) ans += n;
    cout << ans << endl;
    return 0;
}
