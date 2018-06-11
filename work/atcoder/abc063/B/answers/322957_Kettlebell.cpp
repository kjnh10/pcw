#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	//freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
	string s;
	cin >> s;

	VB alpha(26, false);
	for(char c : s)
	{
		int nc = c - 'a';
		if(alpha[nc] == true) {
			cout << "no" << endl;
			return 0;
		}
		alpha[nc] = true;
	}
	cout << "yes" << endl;

	return 0;
}