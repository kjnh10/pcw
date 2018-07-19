#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
vector<pii> point;

double dist(pii p1, pii p2){
  double x = p1.first - p2.first;
  double y = p1.second- p2.second;

  return sqrt(x*x+y*y);
}

int main(){
  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int p,q;
    cin >> p >> q;
    point.push_back(pii(p,q));
  }

  double maxim = 0;
  for(int i=0; i<n; i++){
    pii p = point[i];
    for(int j=i+1; j<n; j++){
      maxim = max(maxim,dist(p, point[j]));
    }
  }

  cout << setprecision(10) << maxim << endl;

  return 0;
}