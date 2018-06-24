#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;

  if(n%400 == 0){
    cout << "YES" << endl;
  }else if(n%100 == 0){
    cout << "NO" << endl;
  }else if(n%4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}