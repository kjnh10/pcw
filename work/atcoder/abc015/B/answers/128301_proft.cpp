#include<iostream>

using namespace std;

int main() {
	int n,res;
	double bug = 0, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		double b;
		cin >> b;
		if (b==0)continue;
		bug++;
		sum += b;
	}
	int nat = sum / bug;
	if (sum / bug > nat)res = nat + 1;
	else res = nat;
	cout << res << endl;
	return 0;
}