#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int l[10000],r[10000];
int main(){
	int n,d,k;scanf("%d%d%d",&n,&d,&k);
	rep(i,d)scanf("%d%d",&l[i],&r[i]);
	rep(i,k){
		int s,t;scanf("%d%d",&s,&t);
		int p=s;
		rep(j,d){
			if(l[j]<=p&&p<=r[j]){
				if(l[j]<=t&&t<=r[j]){
					printf("%d\n",j+1);break;
				}
				if(p<t)p=r[j];
				else p=l[j];
			}
		}
	}
}
