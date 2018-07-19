#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int n, k, x, y;
int main() {
	cin >> n >> k >> x >> y;
	if (k >= n)k = n;
	cout << k*x + (n - k)*y << endl;
	return 0;
}