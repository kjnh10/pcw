#include <stdio.h>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef long long lli;
typedef pair<int,lli> ip;

lli x[100001], v[100001], c;
int n;

lli process() {
	lli sum=0, res=0;
	for(int i=0;i<n;i++) {
		sum+=v[i];
		res=max(res,sum-x[i]);
	}
	set<ip> s;
	sum=0;
	for(int i=n-1;i>=0;i--) {
		sum+=v[i];
		if(sum-(c-x[i])<=0) continue;
		if(s.empty() || sum-(c-x[i])>(*s.begin()).second)
			s.insert(ip(i,sum-(c-x[i])));
	}
	sum=0;
	for(int i=0;i<n;i++) {
		sum+=v[i];
		lli val=sum-2*x[i];
		set<ip>::iterator it=s.lower_bound(ip(i+1,-1));
		if(it!=s.end()) val+=it->second;
		res=max(res,val);
	}
	return res;
}

int main() {
	scanf("%d %lld",&n,&c);
	for(int i=0;i<n;i++)
		scanf("%lld %lld",&x[i],&v[i]);
	lli res=process();
	for(int i=0;i<n;i++)
		x[i]=c-x[i];
	reverse(x,x+n);
	reverse(v,v+n);
	printf("%lld\n",max(res,process()));
	return 0;
}