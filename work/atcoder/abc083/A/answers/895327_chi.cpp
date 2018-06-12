#include <iostream>
#include <vector>
#include <set>

#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define vi vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main(void){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(a+b>c+d)
    cout<<"Left"<<endl;
  else if(a+b<c+d)
    cout<<"Right"<<endl;
  else 
    cout<<"Balanced"<<endl;

  
}