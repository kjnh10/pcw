#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef long long int ll;
const int MOD = 1000000007;

int d[10];
bool C(int n){
  while(n>0){
    int t=n%10;
    if(d[t] == 1){
      return false;
    }
    n /= 10;
  }
  return true;
}
int main(){
  int N,K;
  cin >> N >> K;
  for(int i=0;i<K;i++){
    int t;
    cin >> t;
    d[t] = 1;
  }
  while(1){
    if(C(N)){
      cout << N << endl;
      return 0;
    }
    N++;
  }
}