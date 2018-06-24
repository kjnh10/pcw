#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<math.h>
#define pi 3.141592653589
#include<iomanip>
using namespace std;
#include<algorithm>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 1e9
#define LINF 1e17
#define ll long long
#define MOD (int)(1e9+7)

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};



int main(){
    
    int n,a[100000]={},path[100000]={},sp=0,cnt=0;;
    
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    while(1){
        if(path[sp]){
            cout<<"-1"<<endl;
            break;
        }
        if(sp==1){
            cout<<cnt<<endl;
            break;
        }
        path[sp]=1;
        sp=a[sp]-1;
        cnt++;
    }
        
    return 0;
}