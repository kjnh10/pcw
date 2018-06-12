#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 200005
#define BT 1005
#define ALP 26

using namespace std;
typedef long long int ll;

char str[SIZE];
int KMP[SIZE];
ll len[BT];
ll cnt[BT][ALP];
ll ans[ALP];
ll query[ALP];

void solve(ll L)//[0,L-1]
{
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		if(i==0) KMP[i]=-1;
		else
		{
			KMP[i]=KMP[i-1];
			while(1)
			{
				if(str[KMP[i]+1]==str[i])
				{
					KMP[i]++;
					break;
				}
				if(KMP[i]==-1) break;
				KMP[i]=KMP[KMP[i]];
			}
		}
	}
	int add=KMP[n-1];
	while((add+1)*2>=n) add=KMP[add];
	string T="";
	for(int i=0;i<n-(add+1);i++) T+=str[i];
	for(int i=0;i<T.size();i++)
	{
		if(i==0) KMP[i]=-1;
		else
		{
			KMP[i]=KMP[i-1];
			while(1)
			{
				if(T[KMP[i]+1]==T[i])
				{
					KMP[i]++;
					break;
				}
				if(KMP[i]==-1) break;
				KMP[i]=KMP[KMP[i]];
			}
		}
	}
	add=KMP[T.size()-1];
	while((add+1)*2>T.size()) add=KMP[add];
	add++;
	//printf("%s %d\n",T.c_str(),add);
	int sz=0;
	memset(cnt,0,sizeof(cnt));
	memset(len,0,sizeof(len));
	for(int i=add;i<T.size()-add;i++)
	{
		len[sz]++;
		cnt[sz][T[i]-'a']++;
	}
	sz++;
	for(int i=0;i<add;i++)
	{
		len[sz]++;
		cnt[sz][T[i]-'a']++;
	}
	sz++;
	while(len[sz-1]<=L)
	{
		len[sz]=len[sz-1]+len[sz-2];
		for(int i=0;i<ALP;i++)
		{
			cnt[sz][i]=cnt[sz-1][i]+cnt[sz-2][i];
		}
		//printf("%lld\n",len[sz]);
		sz++;
	}
	memset(query,0,sizeof(query));
	for(int i=sz-1;i>=2;i--)
	{
		if(L>=len[i])
		{
			L-=len[i];
			for(int j=0;j<ALP;j++) query[j]+=cnt[i][j];
		}
	}
	for(int i=0;i<L;i++)
	{
		query[T[i]-'a']++;
	}
}
int main()
{
	scanf("%s",&str);
	ll L,R;
	scanf("%lld %lld",&L,&R);
	solve(R);
	for(int i=0;i<ALP;i++) ans[i]=query[i];
	solve(L-1);
	for(int i=0;i<ALP;i++) ans[i]-=query[i];
	for(int i=0;i<ALP;i++)
	{
		if(i!=0) printf(" ");
		printf("%lld",ans[i]);
	}puts("");
	return 0;
}
