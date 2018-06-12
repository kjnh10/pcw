#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	bool flag = false;
	while(cin >> s){
		if(flag) cout << ' ';
		else flag = true;
		if(s == "Left") cout << '<';
		else if(s == "Right") cout << '>';
		else cout << 'A';
	}
	cout << endl;
	return 0;
}