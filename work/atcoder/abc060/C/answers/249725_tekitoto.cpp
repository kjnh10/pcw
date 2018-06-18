#include <iostream>
#include <vector>

using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, T;
  cin >> N >> T;

  vector<int> t(N+1);
  for(int i=0; i<N; i++){
	cin >> t[i];
  }
  t[N] = t[N-1] + T;

  int sum = 0;
  for(int i=0; i<N; i++){
	sum += (t[i+1] - t[i] <= T) ? t[i+1] - t[i] : T;
  }

  cout << sum << endl;

  return 0;
}
