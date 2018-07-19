#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
  int a[100001]={};
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    a[tmp]++;
  }
  int ans=0;
  int sum=0;
  for(int i=0;i<100001;i++){
    if(a[i]>0){
      ans++;
      sum+= a[i]-1;
    }
  }
  if(sum%2==0)
    cout << ans <<endl;
  else
    cout << ans -1<<endl;
}


