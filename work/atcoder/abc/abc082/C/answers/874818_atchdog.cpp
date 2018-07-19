#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> record;
	for (int i = 0; i < n; i ++) {
		int t; cin >> t;
		record[t] ++;
	}
	map<int, int> :: iterator iter = record.begin();
	
	int ans = 0;
	for (; iter != record.end(); iter ++) {
		if (iter->first > iter->second) 
			ans += iter->second;
		else if (iter->first < iter->second)
			ans += iter->second - iter->first;	
	}
	
	cout << ans << endl;
	return 0;
} 