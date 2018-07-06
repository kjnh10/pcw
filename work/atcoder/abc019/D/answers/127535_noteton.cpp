#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
int N;
using namespace std;
int main(){
  int diameter=0,d=0;
  int dist;
  cin >> N;
  /*
  for(int i=1;i<=N-1;i++){
    for(int j=i+1;j<=N;j++){
      cout << "? " << i << " " << j << endl;
      cin >> dist;
      diameter=max(dist,diameter);
    }
  }
  */
  int mnode;
  for(int i=2;i<=N;i++){
    cout << "? " << 1 << " " << i << endl;
      cin >> dist;
      if(d<dist){
	d=dist;
	mnode=i;
      }
  }
  for(int i=1;i<=N;i++){
    if(i==mnode) continue;
    cout << "? " << mnode << " " << i << endl;
    cin >> dist;
    diameter=max(diameter,dist);
  }
  cout << "! " << diameter << endl;
  return 0;
}
