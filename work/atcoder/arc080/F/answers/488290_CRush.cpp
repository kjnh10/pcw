#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()

const int maxnode=100000+5;
const int maxedge=100000+5;

int nleft,nright,nedge;
int head[maxnode],point[maxedge],nextp[maxedge];
int p1[maxnode],p2[maxnode];
bool visited[maxnode];

void clear()
{
	for (int i=0;i<nleft;i++) p1[i]=-1;
	for (int i=0;i<nright;i++) p2[i]=-1;
}
void init(int _nleft,int _nright)
{
	nleft=_nleft;
	nright=_nright;
	nedge=0;
	for (int i=0;i<nleft;i++) head[i]=-1;
	clear();
}
void addedge(int u,int v)
{
	point[nedge]=v,nextp[nedge]=head[u],head[u]=(nedge++);
}
bool find_path(int v)
{
	for (int k=head[v];k>=0;k=nextp[k])
	{
		int p=point[k];
		if (!visited[p])
		{
			visited[p]=true;
			if (p2[p]<0 || find_path(p2[p]))
			{
				p1[v]=p;
				p2[p]=v;
				return true;
			}
		}
	}
	return false;
}
int doMatch()
{
	for (int i=0;i<nleft;i++)
		for (int k=head[i];p1[i]<0 && k>=0;k=nextp[k])
			if (p2[point[k]]<0)
			{
				p1[i]=point[k];
				p2[point[k]]=i;
			}
	for (int i=0;i<nleft;i++) if (p1[i]<0)
	{
		for (int k=0;k<nright;k++) visited[k]=false;
		find_path(i);
	}
	int result=0;
	for (int i=0;i<nleft;i++) if (p1[i]>=0) result++;
	return result;
}

const int maxn=256;

int n;
int x[maxn];

bool is_prime(int n)
{
	if (n<3) return false;
	for (int m=2;m*m<=n;m++) if (n%m==0) return false;
	return true;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	cin>>n;
	REP(i,n) cin>>x[i];
	set<int> s;
	REP(i,n) s.insert(x[i]);
	set<int> e;
	REP(i,n) for (int d=-2;d<=2;d++) if (x[i]+d>0) e.insert(x[i]+d);
	set<int> w;
	for (int p:e) if (s.count(p)!=s.count(p-1)) w.insert(p);
	vector<int> v1;
	vector<int> v2;
	for (int p:w)
		if (p%2==0) v1.push_back(p);
		else v2.push_back(p);
	init(SIZE(v1),SIZE(v2));
	REP(i,SIZE(v1))
		REP(j,SIZE(v2))
			if (is_prime(abs(v1[i]-v2[j])))
				addedge(i,j);
	int r0=doMatch();
	int l1=SIZE(v1)-r0;
	int l2=SIZE(v2)-r0;
	int ret=r0;
	ret+=l1/2*2;
	ret+=l2/2*2;
	if (l1%2==1 && l2%2==1) ret+=3;
	printf("%d\n",ret);
	return 0;
}

