# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(5e5) + 5;
const int inf = (int)1e9 + 7;

int n;
deque < int > dq;

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(i % 2){
      dq.push_back(x);
    } else{
      dq.push_front(x);
    }
  }
  if(n % 2){
    reverse(dq.begin(), dq.end());
  }
  for(int i : dq){
    printf("%d ", i);
  }
  return 0;
}
