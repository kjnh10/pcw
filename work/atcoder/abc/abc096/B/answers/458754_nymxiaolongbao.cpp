#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    int a[3],k;
    lol(i,3)cin>>a[i];
    sort(a,a+3);
    cin>>k;
    cout<<a[0]+a[1]+(a[2]<<k)<<endl;
    
    return 0;
}
