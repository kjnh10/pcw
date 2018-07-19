#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

int n;
LL K;
struct Point{
	int a, b;
	void read(){
		scanf("%d %d", &a, &b);
	}
	bool operator < (const Point &A)const{
		return a < A.a;
	}
}p[N];

int main(){
	while(~scanf("%d %lld", &n, &K)){
		for(int i=0; i<n; i++){
			p[i].read();
		}
		sort(p, p+n);
		LL cur = 0;
		for(int i=0; i<n; i++){
			cur = cur + p[i].b;
			if(cur >= K){
				printf("%d\n", p[i].a);
				break;
			}
		}
	}
	return 0;
}