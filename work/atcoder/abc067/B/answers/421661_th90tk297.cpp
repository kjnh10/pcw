#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	int n, k; cin >> n >> k;
	int a[60]; for (int i = 0; i < n; i++)cin >> a[i]; sort(a, a + n);
	ll sum = 0;
	for (int i = 0; i < k; i++){
		sum += a[n - 1 - i];
	}
	cout << sum << endl;
}