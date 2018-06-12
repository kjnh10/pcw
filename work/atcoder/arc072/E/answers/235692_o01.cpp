#include<cstdio>
#include<algorithm>

using namespace std;

long long dp[500500];
int x[500500];

int a[500500];
int N;
int D;

void fillAll(){
	x[0] = D;
	for(int i = 0; i < N; ++i){
		int tmp = x[i] - a[i];
		if(tmp < 0) tmp = -tmp;
		x[i + 1] = min(x[i], tmp);
	}
	dp[N] = 1;
	dp[N - 1] = (a[N - 1] == 1 ? 2 : 1);
	for(int i = N - 2; i >= 0; --i){
		if(a[i] < dp[i + 1] * 2) dp[i] = dp[i + 1] + a[i];
		else dp[i] = dp[i + 1];
	}
}

inline bool query(int id){
	return x[id] >= dp[id + 1];
}

void input(){
	scanf("%d%d", &N, &D);
	for(int i = 0; i < N; ++i){
		scanf("%d", a + i);
	}
}

int main(){
	input();
	fillAll();
	int Q;
	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q){
		int id;
		scanf("%d", &id);
		id--;
		bool flg = query(id);
		if(flg) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
