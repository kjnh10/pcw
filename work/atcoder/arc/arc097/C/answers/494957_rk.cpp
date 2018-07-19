#include <bits/stdc++.h>
using namespace std;

string s;
int k;
vector <string> V;

int main()
{
	cin >> s;
	cin >> k;
	for (int i = 0; i < s.length(); i++) {
		string cur;
		for (int j = i; j < s.length() && j < i + k; j++) {
			cur += s[j];
			V.push_back(cur);
		}
	}
	sort(V.begin(), V.end()); V.erase(unique(V.begin(), V.end()), V.end());
	cout << V[k - 1] << endl;
	return 0;
}