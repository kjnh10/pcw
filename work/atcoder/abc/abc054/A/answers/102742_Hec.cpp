#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
	int a,b;
	cin >> a >> b;

	if(a==1) a+=13;
	if(b==1) b+=13;
	
	if(a>b)
		cout << "Alice" << endl;
	else if(a<b)
		cout << "Bob" << endl;
	else
		cout << "Draw" << endl;
	
	return 0;
}