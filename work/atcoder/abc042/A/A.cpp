#include <iostream>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int fcount = 0;
  int scount = 0;
  if (A == 5){fcount+=1;}
  if (B == 5){fcount+=1;}
  if (C == 5){fcount+=1;}
  if (A == 7){scount+=1;}
  if (B == 7){scount+=1;}
  if (C == 7){scount+=1;}
  if (fcount==2 and scount==1){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
