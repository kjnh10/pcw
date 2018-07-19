#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#define SIZE 405

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,P> PP;

int C[SIZE][4];
map <PP,int> mp;

void rem(int a,int b,int c,int d)
{
	mp[PP(P(a,b),P(c,d))]--;
	mp[PP(P(b,c),P(d,a))]--;
	mp[PP(P(c,d),P(a,b))]--;
	mp[PP(P(d,a),P(b,c))]--;
}
void remp(PP p)
{
	rem(p.first.first,p.first.second,p.second.first,p.second.second);
}
void ins(int a,int b,int c,int d)
{
	mp[PP(P(a,b),P(c,d))]++;
	mp[PP(P(b,c),P(d,a))]++;
	mp[PP(P(c,d),P(a,b))]++;
	mp[PP(P(d,a),P(b,c))]++;
}
void insp(PP p)
{
	ins(p.first.first,p.first.second,p.second.first,p.second.second);
}
int same(PP p,PP q)
{
	int a=p.first.first,b=p.first.second,c=p.second.first,d=p.second.second;
	int ret=0;
	if(q==PP(P(a,b),P(c,d))) ret++;
	if(q==PP(P(b,c),P(d,a))) ret++;
	if(q==PP(P(c,d),P(a,b))) ret++;
	if(q==PP(P(d,a),P(b,c))) ret++;
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d %d %d",&C[i][0],&C[i][1],&C[i][2],&C[i][3]);
	vector <PP> vx;
	ll ret=0;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<vx.size();j++)
		{
			PP p=vx[j];
			int a=p.first.first,b=p.first.second,c=p.second.first,d=p.second.second;
			//rem(a,b,c,d);
			PP x=PP(P(C[i][0],C[i][1]),P(b,a));
			PP y=PP(P(C[i][1],C[i][2]),P(c,b));
			PP z=PP(P(C[i][2],C[i][3]),P(d,c));
			PP w=PP(P(C[i][3],C[i][0]),P(a,d));
			ll all=1;
			all*=(ll) mp[x]-same(p,x);
			int A=same(x,y);
			all*=(ll) mp[y]-A-same(p,y);
			int B=same(x,z)+same(y,z);
			all*=(ll) mp[z]-B-same(p,z);
			int D=same(x,w)+same(y,w)+same(z,w);
			all*=(ll) mp[w]-D-same(p,w);
			//if(i==1&&a==1&&b==1&&c==0&&d==0) printf("%d : %d %d %d %d : %d %d %d %d : %lld\n",i,a,b,c,d,mp[x],mp[y],mp[z],mp[w],all);
			ret+=all;
			//ins(a,b,c,d);
		}
		int a=C[i][0],b=C[i][3],c=C[i][2],d=C[i][1];
		ins(a,b,c,d);
		vx.push_back(PP(P(a,b),P(c,d)));
		vx.push_back(PP(P(b,c),P(d,a)));
		vx.push_back(PP(P(c,d),P(a,b)));
		vx.push_back(PP(P(d,a),P(b,c)));
	}
	printf("%lld\n",ret);
	return 0;
}
