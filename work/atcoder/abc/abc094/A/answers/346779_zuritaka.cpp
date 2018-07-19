#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<math.h>

#define print(x) cout << #x << " = " << x << endl;

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;


int main() {
	int A, B, X;

	cin >> A >> B >> X;

	if (A <= X && X - A <= B) cout << "YES" << endl;
	else cout << "NO" << endl;


	return 0;
}