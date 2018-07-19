#include<bits/stdc++.h>
#define F first
#define S second
#define INF (1<<30)
#define LINF (1LL<<60)
using namespace std;
typedef pair<long long,long long> P;
long long a,b,c,d;
string s,s2,s3;
long long  sum=0,ans=0,pos=0;
long long n,m,h,w;
main(){
  cin>>a;
  b=a/11;
  b*=2;
  if(a%11!=0){
    if(a%11<=6) b++;
    else b+=2;
  }
  
  cout<<b<<endl;
}
