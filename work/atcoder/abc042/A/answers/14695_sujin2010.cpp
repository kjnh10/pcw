#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int a[3];
    for(int i=0;i<3;i++)cin>>a[i];
    sort(a,a+3);
    if(a[0]==5&&a[1]==5&&a[2]==7)puts("YES");
    else puts("NO");
    return 0;
}
