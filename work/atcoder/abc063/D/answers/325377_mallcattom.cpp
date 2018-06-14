#include <bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f  
typedef long long ll;  
const int N =  1e5 + 10;  
#define FI first
#define SE second
typedef pair<int, int>pii;
int num[N];
ll tmp[N], n;
bool judge(int cnt, int a, int b)
{
	int d = a - b;
	int lcnt = cnt;
	for (int i = 0; i < n; i++)
	{
		tmp[i] = num[i];
		tmp[i] -= (ll)cnt*b;
		if (tmp[i] <= 0)
			return true;
		int ct = tmp[i] / d + (tmp[i]%d?1:0);
		if (ct > lcnt)
			return false;
		lcnt -= ct;
	}
	return true;
}	
int main()  
{  
  // freopen("in.txt","r",stdin);
   int  a, b;
   while (~scanf("%d%d%d", &n, &a, &b))
   {
   
   	for (int i = 0; i < n; i++)
   	{
   		scanf("%d", num + i);
   	}
   	sort(num, num + n, greater<int>());
   	int l = 0, r = 1e9 + 10;
   	while (l < r)
   	{
   		int mid = l + ((r - l)>>1);
   		if (judge(mid, a, b))
   			r = mid;
   		else
   			l = mid + 1;
   	}
   	printf("%d\n", l);
   }
   
   return 0;  
}  