#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000];
int count(string s, string l, string r){
  dp[0] = 1;
  for(int i=1; i<s.size(); i++){
    if(s.substr(i-1,2) == l || s.substr(i-1,2) == r){
      dp[i] = min(dp[i-2]+1, dp[i-1]+1);
    }else{
      dp[i] = dp[i-1]+1;
    }
  }
  return dp[s.size()-1];
}

int main(){
  int n;
  string s;

  cin >> n;
  cin >> s;

  string t[] = {"AB","AX","AY", "BA","XA","YA",
                "BX","BY","XB","YB", "XY","YX",
                "AA","BB","XX","YY"};

  int r = s.size()+1;
  for(int i=0; i<16; i++)
    for(int j=0; j<16; j++)
      if(i != j)
        r = min(r, count(s,t[i],t[j]));

  cout << r << endl;


  return 0;
}