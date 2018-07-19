#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <math.h>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	cout << stoi(A + B) * 2 << endl;
	return 0;
}