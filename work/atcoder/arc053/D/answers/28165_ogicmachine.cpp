#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	const int n = s.size();
	vector<int> hist(26);
	for(int i = 0; i < n; ++i){ ++hist[s[i] - 'a']; }
	int odd_count = 0, remains = 0;
	for(int i = 0; i < 26; ++i){
		if(hist[i] % 2 != 0){ ++odd_count; }
		remains += hist[i] / 2;
	}
	if(odd_count == 0){
		cout << n << endl;
	}else{
		const int answer = 1 + (remains / odd_count) * 2;
		cout << answer << endl;
	}
	return 0;
}
