#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n,num[100000] = {},a,sum = 0;
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> a;
		num[a - 1]++;
	}
	for(int i = 0;i < 100000;i++) {
		if(num[i] >= 2) sum += num[i] - 1;
	}
	int t = (sum + 1) / 2;
	n -= t * 2;
	cout << n << endl;
	return 0;
}