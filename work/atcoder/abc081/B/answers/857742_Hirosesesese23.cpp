#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <math.h>
using namespace std;

int solve(int x){
    int ans=0;
    while(x%2==0){
        ans++;
        x/=2;
    }
    return ans;
}
int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=solve(a[i]);
    }
    sort(a.begin(),a.end());
    cout<<a[0]<<endl;
    return 0;
}
