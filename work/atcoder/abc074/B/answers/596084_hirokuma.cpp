#include<iostream>
using namespace std;

int main(){
  int N,K,x,sum=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>x;
    if(K-x<x) sum+= 2*(K-x);
    else sum+= 2*x;
  }
  cout<<sum<<endl;
  return 0;
}
