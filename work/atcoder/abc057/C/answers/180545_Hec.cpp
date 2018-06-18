#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int cnt_digits(ll N){
	int digits=0;
	
	while(N>0){
		N/=10;
		digits++;
	}
	
	return digits;
}

int main(void){
	ll N;
	cin >> N;

	int ans=cnt_digits(N); // 1*N=N max(cnt_digits(1),cnt_digits(N))=cnt_digits(N)

	for(ll A=1LL;A*A<=N;++A){
		if(N%A!=0) continue;
		const ll B=N/A;
		
		const int cur=max(cnt_digits(A),cnt_digits(B));

		if(ans>cur){
			ans=cur;
		}
	}

	cout << ans << endl;
	return 0;
}