
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

#define rep(i,n,m) for(int i=n;i<(int)(m);i++)




int main() {

	string str;
	cin >> str;

	bool flag = true;
	

	rep(i, 0, (int)str.size()/2) {
		if (str[i] != '*' && str[str.size() - 1 - i] != '*') {			
				if (str[i] != str[str.size() - 1 - i])flag = false;
		}
	}
	
		

	if (flag)cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	return 0;
}
