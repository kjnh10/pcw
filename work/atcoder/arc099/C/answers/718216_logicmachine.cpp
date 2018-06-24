#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	const int s = k - 1;
	cout << (n + s - 2) / s << endl;
	return 0;
}

