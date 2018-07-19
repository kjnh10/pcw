
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define MOD 1000000007

using ll = long long;


int main(void) {
    long n,z,w;
    cin >> n >> z >> w;
    
    vector<long> yama;
    for(int i=0;i<n;i++){
        long x;
        cin >> x;
        yama.push_back(x);
    }
    if(n==1){
        cout << abs(yama[0] - w) << endl;
        return 0;
    }
    long ans;
    if(abs(yama[n-1]-w) >= abs(yama[n-2] - yama[n-1])){
        ans = abs(yama[n-1] - w);
    }else{
        ans = abs(yama[n-2] - yama[n-1]);
    }
    
    cout << ans << endl;
    return 0;
}
