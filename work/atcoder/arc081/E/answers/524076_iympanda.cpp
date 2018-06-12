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

char s[300000];
int d[300000];
int ne[300000][26];

int main()
{
  int i,j,n,tmp,b1,now;
  scanf("%s",s);
  n=strlen(s);
  memset(ne[n],-1,sizeof(ne[n]));
  for (i=n-1;i>=0;i--)
  {
    memcpy(ne[i],ne[i+1],sizeof(ne[i]));
    ne[i][s[i]-'a']=i;
  }
  d[n]=1;
  for (i=n-1;i>=0;i--)
  {
    d[i]=2000000000;
    for (j=0;j<26;j++)
      if (ne[i][j]==-1)
      {
        d[i]=1;
      }
      else
      {
        tmp=d[ne[i][j]+1]+1;
        if (tmp<d[i]) d[i]=tmp;
      }
  }
  now=0;
  while (1)
  {
    b1=0;
    for (j=0;j<26;j++)
    {
      tmp=ne[now][j];
      if (tmp==-1)
      {
        printf("%c",'a'+j);
        b1=1;break;
      }
      else
      {
        if (d[tmp+1]+1==d[now])
        {
          printf("%c",'a'+j);
          now=tmp+1;
          break;
        }
      }
    }
    if (b1==1) break;
  }
  printf("\n");
  return 0;
}