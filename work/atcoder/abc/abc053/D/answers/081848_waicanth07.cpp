#include <cstdio>
using namespace std;

int n;
int a[1000001];
int ans;
int s;

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int t;
		scanf("%d", &t);
		a[t]++;
		ans++;
		if(a[t] > 2){
			a[t] -= 2;
			ans -= 2;
		}
	}

	for(int i=1; i<100001; i++)
		if(a[i] == 2) s++;

	ans -= (s / 2) * 2;
	s %= 2;

	if(s == 1) ans -= 2;

	printf("%d\n", ans);
}