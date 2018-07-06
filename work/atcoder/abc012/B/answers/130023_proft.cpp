#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int h=0, m=0, s=0;

	h = n / 3600;
	n -= h * 3600;

	m = n / 60;
	n -= m * 60;

	s = n;

	printf("%02d:%02d:%02d\n", h, m, s);

	return 0;
}