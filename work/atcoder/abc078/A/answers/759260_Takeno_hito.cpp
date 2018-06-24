#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 100000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
// #define int long long
/* define/include */

int main(){
  char x,y;
  cin >> x >> y;
  if(x<y){
    cout << "<";
  }if(x==y){
    cout << "=";
  }if(x>y){
    cout << ">";
  }
  return 0;
}
