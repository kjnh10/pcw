#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int cnt[N + 5];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i < n; ++i){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int maks = 0;
	for(int i = 0;i < N; ++i){
		int x = (i == 0) ? 0 : cnt[i-1];
		int y = cnt[i];
		int z = (i == N - 1) ? 0 : cnt[i + 1];
		maks = max(maks, x + y + z);
	}
	printf("%d\n", maks);
	return 0;
}