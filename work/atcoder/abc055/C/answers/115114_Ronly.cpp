#include <iostream>
using namespace std;

int main() {
	long long n, m, ans;
	cin >> n >> m;
	
	if(m >= n*2){
		ans += n;
		m = m-n*2;
		ans += m/4;
	}else{
		ans = m/2;
	}
	cout << ans << endl;
	return 0;
}