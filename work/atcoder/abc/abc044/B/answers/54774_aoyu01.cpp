#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define ll long long
using namespace std;
map<int,int>mp;
int main()
{
    string s;
    while(cin>>s){
      int n=s.size();
      mp.clear();
      for(int i=0;i<n;i++)mp[s[i]-'a']++;
      n=0;
      for(int i=0;i<26;i++)n+=(mp[i]%2);
      n?puts("No"):puts("Yes");
    }
    return 0;
}
