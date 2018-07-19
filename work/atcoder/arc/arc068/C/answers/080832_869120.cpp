#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
long long n;
int main() {
	cin >> n;
	long long Y1 = n / 11; Y1 *= 2;
	long long Y2 = n % 11;
	if (Y2 >= 1)Y1 += 1;
	if (Y2 >= 7)Y1 += 1;
	cout << Y1 << endl;
	return 0;
}