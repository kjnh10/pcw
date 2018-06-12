#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

#define _int64 long long

int a[200000];
_int64 ans[200000];

int main()
{
  vector<pair<int,int> > aa;
  int i,n;
  _int64 now,nowind,nowcnt;
  scanf("%d",&n);
  for (i=0;i<n;i++)
    scanf("%d",&a[i]);
  aa.clear();
  for (i=0;i<n;i++)
    aa.push_back(make_pair(a[i],-i));
  sort(aa.begin(),aa.end());
  reverse(aa.begin(),aa.end());
  now=2000000000;nowind=-1;
  memset(ans,0,sizeof(ans));
  nowcnt=0;
  for (i=0;i<aa.size();i++)
  {
    if (nowind==-1)
    {
      nowind=-aa[i].second;now=aa[i].first;
      nowcnt++;
    }
    else
    {
      ans[nowind]+=nowcnt*(now-aa[i].first);
      now=aa[i].first;
      if (-aa[i].second<nowind) nowind=-aa[i].second;
      nowcnt++;
    }
  }
  ans[nowind]+=nowcnt*now;
  for (i=0;i<n;i++)
    printf("%lld\n",ans[i]);
  
  return 0;
}