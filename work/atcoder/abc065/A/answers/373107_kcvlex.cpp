#include<iostream>
using namespace std;

int main(){
	int x, a, b; cin >> x >> a >> b;
	cout << (a - b >= 0 ? "delicious\n" : (a + x - b >= 0 ? "safe\n" : "dangerous\n"));
	return 0;
}