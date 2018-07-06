#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int a, b, c;

	cin >> a >> b >> c;

	if (a + b == c&&a-b==c) {
		cout << "?" << endl;
	}else if(a + b == c && a - b != c){
		cout << "+" << endl;
	}
	else if (a + b != c && a - b == c) {
		cout << "-" << endl;
	}
	else if(a+b!=c&&a-b!=c){
		cout << "!" << endl;
	}
	
	return 0;
}