#include<bits/stdc++.h>
using namespace std;
int a, b, n, maj = 0, cnt = 1, rt[4005], non[4005];

int main()
{
	scanf("%d%d",&a,&b);
	n = a+b;
	if(a <= b) {puts("Impossible"); return 0;}
	for(int i = 1; i < n; i++) {
		char r1[2], r2[2];
		printf("? %d %d\n", maj, i);
		fflush(stdout);
		scanf("%s",r1);
		if(r1[0] == 'N') {
			rt[i] = i;
			cnt--;
			if(cnt < 0) {cnt = 1; maj = i;}
			continue;
		}
		printf("? %d %d\n", i, maj);
		fflush(stdout);
		scanf("%s",r2);
		if(r2[0] == 'N') {
			non[maj] = 1;
			rt[i] = i;
			cnt = 1;
			maj = i;
		}
		else {
			rt[i] = maj;
			cnt++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i == maj || non[i]) continue;
		if(rt[i] != i) {non[i] = non[rt[i]]; continue;}
		char r[2];
		printf("? %d %d\n", maj, i);
		fflush(stdout);
		scanf("%s",r);
		non[i] = (r[0] == 'N');
	}
	printf("! ");
	for(int i=0;i<n;i++) {
		printf("%d",1-non[i]);
	}
	puts("");
}
