#include<iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int ans = 0;
	bool used[n] = {0};
	int a[n];
	int now = 0;
	for(int i = 0; i < n; ++i){
		int b; cin >> b;
		a[i] = b - 1;
	}
	while(1){
		++ans;
		if(a[now] == 1){
			cout << ans << endl;
			break;
		}else if(used[a[now]]){
			cout << -1 << endl;
			break;
		}else{
			used[a[now]] = 1;
			now = a[now];
		}
	}
	return 0;
}