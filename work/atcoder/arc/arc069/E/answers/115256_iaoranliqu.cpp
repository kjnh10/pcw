#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 100005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,n,p,k,a[N];
long long Ans[N];
map<int,int>mp,id;
int main()
{
	scanf("%d",&n); int nowmin=n+1,sum=0;
	for (i=1;i<=n;++i)
	{
			 scanf("%d",&a[i]);
			 mp[a[i]]++;
			 if (id.find(a[i])==id.end()) id[a[i]]=i;
	}
	mp[0]++;
	for (map<int,int>::iterator it=--mp.end();;--it)
	{
			if (it==mp.begin()) break;
			nowmin=min(nowmin,id[it->fi]);
			sum+=it->se;
			--it;
			int last=it->fi;
			++it;
			Ans[nowmin]+=1ll*(it->fi-last)*sum;
	}
	for (i=1;i<=n;++i) printf("%lld\n",Ans[i]);
}
