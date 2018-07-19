#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , d , x , a;
    cin>>n>>d>>x;
    while (n--) {
        cin>>a;
        x += 1 + (d - 1) / a;
    }
    cout<<x<<endl;
    return 0;
}

