#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

bool isvalid(vector<pii> &vp){
  bool x[8], y[8], z1[8+7], z2[8+7];
  for(auto &v: x) v = false;
  for(auto &v: y) v = false;
  for(auto &v: z1) v = false;
  for(auto &v: z2) v = false;

  for(auto &v: vp){
    x[v.first]  = true;
    y[v.second] = true;
    z1[v.first-v.second+7] = true;
    z2[v.first+v.second] = true;
  }

  int c=0;
  for(auto &v: x)
    if(v) c++;
  if(c < vp.size()) return false;

  c=0;
  for(auto &v: y)
    if(v) c++;
  if(c < vp.size()) return false;

  c=0;
  for(auto &v: z1)
    if(v) c++;
  if(c < vp.size()) return false;

  c=0;
  for(auto &v: z2)
    if(v) c++;
  if(c < vp.size()) return false;

  return true;
}

bool hasx(int x, vector<pii> &vp){
  for(auto &v: vp)
    if(v.first==x) return true;
  return false;
}
bool hasy(int y, vector<pii> &vp){
  for(auto &v: vp)
    if(v.second==y) return true;
  return false;
}
bool hasz1(int z, vector<pii> &vp){
  for(auto &v: vp)
    if(v.first-v.second==z) return true;
  return false;
}
bool hasz2(int z, vector<pii> &vp){
  for(auto &v: vp)
    if(v.first+v.second==z) return true;
  return false;
}
bool haspos(int x, int y, vector<pii> &vp){
  for(auto &v: vp)
    if(v.first==x && v.second==y) return true;
  return false;
}

vector<pii> ans;
bool dfs(int pos, vector<pii> vp){
  if(pos >= 64) return false;
  if(vp.size() == 8){
    if(isvalid(vp)){
      ans = vp;
      return true;
    }
    return false;
  }

  int x = pos/8;
  int y = pos%8;

  if(!hasx(x,vp) && !hasy(y,vp) && !hasz1(x-y,vp) && !hasz2(x+y,vp)){
    auto tmp = vp;
    tmp.push_back(pii(x,y));
    if(dfs(pos+1,tmp)) return true;
  }

  if(dfs(pos+1,vp)) return true;

  return false;
}

int main(){
  vector<pii> b;

  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      char c;
      cin >> c;
      if(c == 'Q'){
        b.push_back(pii(i,j));
      }
    }
  }

  if(dfs(0,b)){
    for(int i=0; i<8; i++){
      for(int j=0; j<8; j++){
        if(haspos(i,j,ans)){
          cout << "Q";
        }else{
          cout << ".";
        }
      }
      cout << endl;
    }
  }else{
    cout << "No Answer" << endl;
  }

  return 0;
}