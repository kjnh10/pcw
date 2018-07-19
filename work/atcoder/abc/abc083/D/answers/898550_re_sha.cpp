#include<bits/stdc++.h>
using namespace std;
void wt_L(int x){
  char f[10];
  int m=0, s=0;
  if(x<0){
    m=1,
    x=-x;
  }
  while(x){
    f[s++]=x%10,
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
int main(){
  string s;
  cin >> s;
  int n = s.size();
  int l = (n-1)/2;
  int r = n/2;
  char c = s[l];
  while (l >= 0){
    if (s[l] != c){
      break;
    }
    if (s[r] != c){
      break;
    }
    l--;
    r++;
  }
  int w = (n+r-l-1)/2;
  wt_L(w);
  putchar_unlocked('\n');
  return 0;
}
// cLay varsion 20170910-1

// --- original code ---
// {
//   string s;
//   cin >> s;
//   inplace_L int n = s.size();
//   inplace_L int l = (n-1)/2, r = n/2;
//   inplace_L char c = s[l];
//   while (l >= 0) {
//     if (s[l] != c) break;
//     if (s[r] != c) break;
//     l--; r++;
//   }
//   inplace_L int w = (n+r-l-1)/2;
//   wt(w);
// }