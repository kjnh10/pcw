#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int sum = 700;
	for(int i=0;i<3;i++){
		if(s[i] == 'o') sum+=100;
	}
	cout << sum << endl;
	return 0;
}