#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <map>
#include <set>
using namespace std;
const long INF = 1000000009;

long m, n;

int main(){
	cin >> n >> m;
	long ans = 1;
	for(int i = 0; i < m; i++){
		ans *= 2;
	}
	ans *= 100*(n-m) + 1900*m;
	cout << ans << endl;
	return 0;
}