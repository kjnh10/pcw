#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 2005
#define MX 10005

using namespace std;

char instr[MX];
string str[SIZE];
bool dp[2][MX];
bool can[SIZE][MX];
int gt[MX*2];
string ans;

string get_in()
{
	scanf("%s",&instr);
	string ret=instr;
	return ret;
}
void Z_algo(string s)
{
	gt[0]=0;
	int c=0;
	for(int i=1;i<=s.size();i++)
	{
		if(i+gt[i-c]<c+gt[c]) gt[i]=gt[i-c];
		else
		{
			int to=max(0,c+gt[c]-i);
			while(i+to<s.size()&&s[i+to]==s[to]) to++;
			gt[i]=to;
			c=i;
		}
	}
	gt[0]=s.size();/*
	printf("%s\n",s.c_str());
	for(int i=0;i<=s.size();i++) printf("%d ",gt[i]);puts("");*/
}
int main()
{
	int n,K;
	scanf("%d %d",&n,&K);
	for(int i=0;i<n;i++) str[i]=get_in();
	can[n][0]=true;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<=K;j++)
		{
			if(can[i+1][j])
			{
				can[i][j]=true;
				if(j+str[i].size()<=K) can[i][j+str[i].size()]=true;
			}
		}
	}
	int pos=0;
	memset(dp,false,sizeof(dp));
	dp[pos][0]=true;
	for(int i=0;i<n;i++)
	{
		//printf("%s\n",ans.c_str());
		//for(int j=0;j<=K;j++) printf("%d ",dp[pos][j]);puts("");
		pos^=1;
		memset(dp[pos],false,sizeof(dp[pos]));
		Z_algo(str[i]+ans);
		int bef=-1;
		for(int j=0;j<=K;j++)
		{
			if(!dp[pos^1][j]||j+str[i].size()>K||!can[i+1][K-(j+str[i].size())]) continue;
			if(bef==-1) bef=j;
			else//bef+Sとj+Sを比較 -> |bef|～j-1までとSがどれだけ一致するか
			{
				int to;
				int len=min(gt[str[i].size()+bef],(int) str[i].size());
				if(len<j-bef) to=bef+len;
				else
				{
					len=min(gt[j-bef],(int) str[i].size()-(j-bef));
					to=j+len;
				}
				//printf("* %d %d : %d %d\n",bef,j,to,len);
				if(to==bef+str[i].size()) bef=j;
				else
				{
					char l=str[i][to-bef];
					char r=to<j?ans[to]:str[i][to-j];
					if(l>r) bef=j;
				}
			}
		}//+Sするときの最小の中での最大を求めた
		if(bef==-1)
		{
			pos^=1;
			continue;
		}
		bool up=true;
		for(int j=K;j>=0;j--)
		{
			if(!dp[pos^1][j]||!can[i+1][K-j]) continue;
			//jまでとbef+S比較
			if(j<=bef) break;
			int len=min(gt[str[i].size()+bef],min((int) str[i].size(),j-bef));
			if(bef+len==bef+str[i].size()) up=false;
			else
			{
				if(bef+len<j)
				{
					char l=str[i][len];
					char r=ans[bef+len];
					if(l>r) up=false;
				}
			}
			break;
		}
		if(!up)
		{
			for(int j=0;j<=K;j++)
			{
				dp[pos][j]=dp[pos^1][j]&&can[i+1][K-j];
			}
			continue;
		}
		//printf("%d\n",bef);
		ans.resize(bef);
		ans+=str[i];
		for(int j=0;j<=bef;j++)
		{
			if(!dp[pos^1][j]||!can[i+1][K-(j+str[i].size())]) continue;
			//bef+Sとj+Sを比較
			int to;
			int len=min(gt[str[i].size()+j],(int) str[i].size());
			if(len<bef-j) to=j+len;
			else
			{
				len=min(gt[bef-j],(int) str[i].size()-(bef-j));
				to=bef+len;
			}
			if(to==j+str[i].size()) dp[pos][j+str[i].size()]=true;
		}
		//このままでokのやつも追加
		for(int j=0;j<bef+str[i].size();j++)
		{
			if(!dp[pos^1][j]||!can[i+1][K-j]) continue;
			if(j<=bef) dp[pos][j]=true;
			else
			{
				int len=min(gt[str[i].size()+bef],j-bef);
				dp[pos][j]=bef+len==j;
			}
		}
	}
	printf("%s\n",ans.c_str());
	return 0;
}
