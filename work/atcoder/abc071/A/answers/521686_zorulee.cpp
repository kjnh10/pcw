#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    while(cin>>n>>a>>b){
        puts(abs(n-a)<abs(n-b)?"A":"B");
    }
    return 0;
}
