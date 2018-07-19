#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, T, B = "~";
bool isOK(string A1, string A2) {
	for (int i = 0; i < A1.size(); i++) {
		if (A1[i] != '?' && A1[i] != A2[i])return false;
	}
	return true;
}
int main() {
	cin >> S >> T;
	for (int i = 0; i <= (int)S.size() - (int)T.size(); i++) {
		string U = S.substr(i, T.size());
		if (isOK(U, T) == true) {
			string V = S;
			for (int j = i; j < i + T.size(); j++)V[j] = T[j - i];
			for (int j = 0; j < i; j++) { if (V[j] == '?')V[j] = 'a'; }
			for (int j = i + T.size(); j < V.size(); j++) { if (V[j] == '?')V[j] = 'a'; }
			B = min(B, V);
		}
	}
	if (B == "~")cout << "UNRESTORABLE" << endl;
	else cout << B << endl;
	return 0;
}