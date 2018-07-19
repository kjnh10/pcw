#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		if(A<B) swap(A,B);
		//A>=B -> (A+1)*(B-1) < A*B -> (A+i)*(B-i) < A*B
		//1~B-1 はすべて作れる
		//B+1～は傾き同じになるところを二分探索
		ll l=B,r=INF;
		while(r-l>1)
		{
			ll m=(l+r)/2;
			if(((ll) A*(ll) B-1) >= m*(m+1)) l=m;
			else r=m;
		}
		//r は ok
		ll ret=r-2;
		ret+=((ll) A*(ll) B-1)/r;
		printf("%lld\n",ret);
		//printf("%d %d : %lld\n",A,B,r);
	}
	return 0;
}
