#include<cstdio>
#include<algorithm>
#include<queue>
#define mp make_pair 
using namespace std;
typedef long long ll;
typedef pair<ll,int>pa;
const ll INF=1LL<<61;
ll x[200010],a[200010];
struct que{
	priority_queue<pa>q;
	int flag[100010];
	void Push(pa x)
	{
		q.push(x);
	}
	pa Top()
	{
		while (!q.empty()&&flag[q.top().second]) q.pop();
		if (q.empty()) return mp(-INF,0);
		return q.top();
	}
	void Del(int pos)
	{
		flag[pos]=1;
	}
}Q1,Q2;
int main()
{
	int n;
	ll C;
	scanf("%d%lld",&n,&C);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&a[i]);
	}
	ll val=0;
	for (int i=n;i;i--)
	{
		ll dist=C-x[i];
		val+=a[i];
		Q1.Push(mp(val-dist,i));
	}
	ll ans=max(0LL,Q1.Top().first);
	val=0;
	for (int i=1;i<=n;i++)
	{
		val+=a[i];
		ll dist=x[i];
		Q1.Del(i);
		ans=max(ans,val-dist-dist+Q1.Top().first);
	}
	val=0;
	for (int i=1;i<=n;i++)
	{
		ll dist=x[i];
		val+=a[i];
		Q2.Push(mp(val-dist,i));
	}
	ans=max(ans,Q2.Top().first);
	val=0;
	for (int i=n;i;i--)
	{
		val+=a[i];
		ll dist=C-x[i];
		Q2.Del(i);
		ans=max(ans,val-dist-dist+Q2.Top().first);
	}
	printf("%lld\n",ans);
	return 0;
 } 