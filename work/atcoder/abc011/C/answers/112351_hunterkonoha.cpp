#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <string.h>
 
using namespace std;

int dp[301];

int main(){
    for(int i = 0; i < 301; ++i){
        dp[i] = 10000000;
    }
    int N, NG1, NG2, NG3;
    cin >> N >> NG1 >> NG2 >> NG3;
    dp[N] = 0;
    if (N > 3){
     for(int i = N; i >= 0; --i){
         if (i != NG1 && i != NG2 && i != NG3){
             for(int j = 1; j <= 3; ++j){
                 dp[i - j] = min(dp[i] + 1, dp[i - j]);
             }
         }
     }
     }else{
         if (N != NG1 && N != NG2 && N != NG3){
             dp[0] = 0;
         }
     }
    if (dp[0] <= 100){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
   // for(int i=0;i<N;++i)cout<<dp[i]<<endl;
    return 0;
}