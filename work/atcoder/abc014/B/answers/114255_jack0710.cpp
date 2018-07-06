#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#define PI 3.14159265359
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int a[20], ans = 0;;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int i = 0;
	while(1) {
		if (x % 2)ans += a[i];
		x /= 2;
		++i;
		if (x <= 0)break;
	}

	cout << ans << endl;
	return 0;
}