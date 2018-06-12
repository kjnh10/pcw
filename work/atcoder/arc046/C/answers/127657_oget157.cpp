#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int mod = n % 9;
	if(mod == 0) mod = 9;
	for(int i = 0;i < (n - 1) / 9 + 1;i++) cout << mod;
	cout << endl;
	return 0;
}