#include <iostream>
using namespace std;

int main(){
	int x,y,k,res = 0;
	cin >> x >> y >> k;
	if(y >= k) res = x + k;
	else res = y + x - (k - y);
	cout << res << endl;
	return 0;
}