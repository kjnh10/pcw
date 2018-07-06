#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;

    int a[N];
    for(int i=0; i<N; i++) cin >> a[i];

    int sum[N]; sum[0] = a[0];
    for(int i=1; i<N; i++) sum[i] = sum[i-1] + a[i];
	  

    if( sum[N-1] % N != 0 ){
	cout << -1 << endl;
	return 0;
    }
    int ans = 0;
    for(int i=0; i<N-1; i++){
	if( sum[i] != sum[N-1]*(i+1)/N ) ans++; 
    }
    cout << ans << endl;
			

}
