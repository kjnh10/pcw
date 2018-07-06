#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int ttime[2000000];


int main(){
	int n,t;
	cin >> n >> t;
	
	int k;
	for(int i=0; i<n; i++){
		cin >> k;
		ttime[k]++;
		ttime[k+t]--;
	}

	int cnt=0;
	for(int i=0; i<1500000; i++){
		ttime[i+1]+=ttime[i];
		if(ttime[i]>0){
			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}