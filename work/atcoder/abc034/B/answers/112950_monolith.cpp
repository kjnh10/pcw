#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	long long int n;
	
	cin >> n;
	
	if(n % 2 == 0){
		cout << n - 1 << endl;
	}else{
		cout << n + 1 << endl;
	}
	
	return 0;
}

