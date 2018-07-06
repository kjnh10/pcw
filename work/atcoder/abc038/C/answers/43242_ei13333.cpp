#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, A[100000];
  
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];

  long long ret = 0;
  int back = 0;
  for(int i = 1; i < N; i++) {
    if(A[i - 1] >= A[i]) back = i;
    ret += i - back + 1;
  }
  cout << ret + 1 << endl;
}
