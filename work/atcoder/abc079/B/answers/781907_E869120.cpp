#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <ctime>
using namespace std;
#pragma warning(disable: 4996)
long long a[10009], n;
int main() {
	cin >> n;
	a[0] = 2; a[1] = 1; for (int i = 2; i < 88; i++)a[i] = a[i - 1] + a[i - 2];
	cout << a[n] << endl;
	return 0;
}