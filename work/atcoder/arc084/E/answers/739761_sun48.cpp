#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    LL k, n;
    cin >> k >> n;
    if(k % 2 == 0){
        cout << k/2;
        for(LL j = 0; j < n-1; j++){
            cout << " " << k;
        }
        cout << endl;
        return 0;
    }
    LL m = (k+1)/2;
    vector<LL> d(n, m);
    LL dec = n/2;
    while(dec > 0){
        dec--;
        if(d[d.size()-1] == 1){
            d.pop_back();
            continue;
        }
        d[d.size()-1]--;
        while(d.size() < n){
            d.push_back(k);
        }
        continue;
    }
    for(int i = 0; i < d.size(); i++){
        cout << d[i] << " ";
    }
    cout << endl;
}
