#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
#define rep(i,m,n) for(int i = (m);i < (n);i++)
#define P pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;
#define Vec(a) vector <int> a
const int INF = 1 << 20;
const int MOD = 1e9+7;





int main(){
  string s;
  int n;
  cin >> n;
  cin >> s;
  
  int mn = 1000000;
  int Enum[s.size()] = {};
  int wnum[s.size()] = {};
  REP(i,s.size()){
    if(s[i] == 'E'){
      Enum[i]++;
    }
    else{
      wnum[i]++;
    }
    if(i > 0){
      wnum[i] += wnum[i-1];
      Enum[i] += Enum[i-1];
    }
  }
  REP(i,s.size()){
    if(i == 0){
      mn = min(mn,Enum[s.size()-1]-Enum[0]);
    }
    else if(i == s.size()-1){
      mn = min(mn,wnum[i-1]);
    }
    else{
      mn = min(mn,wnum[i-1]+Enum[s.size()-1]-Enum[i-1]);
    }
  }
  cout << mn << endl;
  return 0;
}
