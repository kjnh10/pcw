#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string S[100]; int n, l;
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)cin >> S[i];
	sort(S, S + n);
	for (int i = 0; i < n; i++)cout << S[i];
	cout << endl;
	return 0;
}