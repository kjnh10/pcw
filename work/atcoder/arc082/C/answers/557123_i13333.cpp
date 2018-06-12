#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N, A[100001] = {};

  cin >> N;
  for(int i = 0; i < N; i++) {
    int X;
    cin >> X;
    A[X]++;
  }

  int ret = 0;
  for(int i = 1; i < 100000; i++) {
    ret = max(ret, A[i - 1] + A[i] + A[i + 1]);
  }

  cout << ret << endl;

}