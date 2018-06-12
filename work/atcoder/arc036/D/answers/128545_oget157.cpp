#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,h,prev = -1,pm[300001] = {},cnt = 0;
	bool minus = false;
	cin >> n;
	for(int i = 0;i < n;i++){
		scanf("%d",&h);
		if(prev != -1){
			if(prev < h){
				if(minus) pm[++cnt]++;
				else pm[cnt]++;
				minus = false;
			}else{
				if(!minus) pm[++cnt]++;
				else pm[cnt]++;
				minus = true;
			}
		}
		prev = h;
	}
	cnt++;
	int ma = 0;
	for(int i = 0;i <= cnt / 2;i++){
		ma = max(ma,pm[i * 2] + pm[i * 2 + 1]);
	}
	cout << ma + 1 << endl;
	return 0;
}