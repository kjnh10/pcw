#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,x,ings=0,mini=1500;
    cin>>n>>x;
    int ing[n];
    for (int i = 0; i < n; ++i) {
        cin>>ing[i];
        ings+=ing[i];
        mini=min(mini,ing[i]);
    }
    cout<<(x-ings)/mini+n<<endl;
    return 0;
}