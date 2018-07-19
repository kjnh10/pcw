#include<bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;

    vector<bool> prime(1000000, true);     //1000000までで、素数ならtrue
    prime[0] = prime[1] = false;
    for(int i = 2; i < 1000000; i++){
        if(prime[i] == true){
            for(int j = 2*i; j < 1000000; j += i){
                prime[j] = false;
            }
        }
    }

    int idx = 0;
    vector<int> ans(n);

    for(int i = 2; i < 1000000; i++){
        if(prime[i] && i % 5 == 1){
            ans[idx] = i;
            idx++;
        }

        if(idx == n) break;
    }

    for(int i = 0; i < n; i++){
        if(i == n - 1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
}