#include <iostream>
#include <string>
using namespace std;

int pop[100100];

int main() {
	int K = 1;
	string S;
	cin >> S;
	int n = S.size()/2;
	if(S.size() % 2 == 0) {
		if(S[n] != S[n-1]) {
			K = S.size()/2;
		}
		else {
			int a;
			a = 0;
			for(int i = 0; i < S.size()/2; i++) {
				if(S[n] == S[n+i] && S[n-1] == S[n-1 -i]) a++;
				else break;
			}
			K = S.size() / 2 + a;
		}
	}
	else {
			int a;
			a = 0;
			for(int i = 0; i <= S.size()/2; i++) {
				if(S[n] == S[n+i] && S[n] == S[n-i]) a++;
				else break;
			}
			K = S.size() / 2 + a;
	}
	cout << K << endl;
}
