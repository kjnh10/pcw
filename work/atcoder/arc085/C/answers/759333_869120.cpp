#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<map>
using namespace std;
#pragma warning(disable: 4996)
int n, m;
int main() {
	cin >> n >> m;
	int z = n * 100 + m * 1800;
	cout << z*(1 << m) << endl;
	return 0;
}