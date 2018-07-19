#include <iostream>
#include <vector>
#include <string>
#include <utility>
#define ll long long int
using namespace std;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int main() {
	string a, b;
	cin >> a >> b;
	string complete = "";
	for(int i = 0; i < a.length() + b.length(); i++) {
		if(i % 2 == 0) {
			complete = complete + a[i / 2];
		} else {
			complete = complete + b[i / 2];
		}
	}
	cout << complete << endl;
}
