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

char s[200000];
char ans[200000];

int main()
{
  int i,j,n,b1;
  char tmp;
  scanf("%d",&n);
  scanf("%s",s);
  b1=0;
  ans[n]='\0';
  for (i=0;i<4;i++)
  {
    if (i/2==0) ans[0]='S';
    else ans[0]='W';
    if (i%2==0) ans[1]='S';
    else ans[1]='W';
    for (j=2;j<n;j++)
    {
      tmp=s[j-1];
      if (ans[j-1]=='W') tmp='o'+'x'-tmp;
      if (tmp=='o') ans[j]=ans[j-2];
      else ans[j]='S'+'W'-ans[j-2];
    }

    if (ans[n-2]==ans[0]) tmp='o';
    else tmp='x';
    if (ans[n-1]=='W') tmp='o'+'x'-tmp;
    if (tmp!=s[n-1]) continue;
    
    if (ans[n-1]==ans[1]) tmp='o';
    else tmp='x';
    if (ans[0]=='W') tmp='o'+'x'-tmp;
    if (tmp!=s[0]) continue;

    b1=1;break;
  }
  if (b1==0) printf("-1\n");
  else printf("%s\n",ans);
  return 0;
}