#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int h, m, s;
	cin >> s;
	h = s / 3600;
	s -=h*3600;
	m = s / 60;
	s -= m * 60;
	printf("%02d:%02d:%02d\n", h, m, s);
	return 0;
}