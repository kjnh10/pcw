#include <iostream>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main() {
	string s[3];
	rep(i,3) cin >> s[i];
	int idx[3]={};
	int curr = 0;
	while(idx[curr] < s[curr].length()) {
		int next = s[curr][idx[curr]] - 'a';
		idx[curr]++;
		curr = next;
	}
	cout << (char)('A'+curr) << endl;
	return 0;
}