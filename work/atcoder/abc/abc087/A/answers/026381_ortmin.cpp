#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1000007;
int a[maxn];
int n,m,k;
int main()
{
    cin>>n>>m>>k;
    int now = n-m;
    cout<<now%k<<endl;
}
