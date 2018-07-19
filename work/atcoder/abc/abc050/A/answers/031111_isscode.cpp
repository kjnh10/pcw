#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	long long A, B;
	char op;
	cin >> A >>op>> B;

	if (op == '+') cout << A + B << endl;
	else cout << A - B << endl;

	return 0;
}