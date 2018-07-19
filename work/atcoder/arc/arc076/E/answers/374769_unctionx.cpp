#include<stdio.h>
#include<algorithm>
using namespace std;

struct intv {
	int s, e;
	bool operator< (const intv& c) const {
		return s<c.s;
	}
} ba[101010];

int R, C, N, cnt, stk[101010], scn;

int val(int x, int y){
	if(y==0) return x;
	if(x==R) return y+R;
	if(y==C) return R+C+(R-x);
	if(x==0) return R+C+R+(C-y);
	return -1;
}

int main(){
	scanf("%d%d%d", &R, &C, &N);
	for(int i=0; i<N; i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1=val(x1,y1), x2=val(x2,y2);
		if(x1<0 || x2<0) continue;
		if(x1>x2)swap(x1,x2);
		ba[cnt].s = x1, ba[cnt].e = x2;
		cnt++;
	}
	sort(ba, ba+cnt);
	for(int i=0; i<N; i++){
		while(scn){
			if(stk[scn-1] > ba[i].e) break;
			if(stk[scn-1] > ba[i].s){ puts("NO"); return 0; }
			scn--;
		}
		stk[scn++] = ba[i].e;
	}
	puts("YES");
	return 0;
}
