#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<set>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
signed main() {
	int a, b; cin >> a >> b;
	if (a > b)cout << a - 1 << endl;
	else cout << a << endl;
}