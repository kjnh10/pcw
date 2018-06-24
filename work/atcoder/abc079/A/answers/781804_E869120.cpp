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
string S;
int main() {
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2])cout << "Yes" << endl;
	else if (S[1] == S[2] && S[2] == S[3])cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}