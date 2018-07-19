#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,m,a[100000];
	bool used[100000] = {};
	cin >> n >> m;
	for(int i = 0;i < m;i++) {
		scanf("%d",&a[i]);
		a[i]--;
	}
	for(int i = m - 1;i >= 0;i--){
		if(!used[a[i]]){
			printf("%d\n",a[i] + 1);
			used[a[i]] = true;
		}
	}
	for(int i = 0;i < n;i++){
		if(!used[i]){
			printf("%d\n",i + 1);
		}
	}
	return 0;
}