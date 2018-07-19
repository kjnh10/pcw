#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int no, v;
};
node a[200005];
int ans[200005];
bool cmp(node a, node b){
	return a.v < b.v;
}
int main(){
	int i, n;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i].v);
		a[i].no=i;
	}
	sort(a+1, a+1+n, cmp);
	for(i=1; i<=n; i++){
		if(i<=n>>1)
			ans[a[i].no]=a[(n>>1)+1].v;
		else
			ans[a[i].no]=a[(n>>1)].v;
	}
	for(i=1; i<=n; i++)
		printf("%d\n", ans[i]);
	return 0;
}