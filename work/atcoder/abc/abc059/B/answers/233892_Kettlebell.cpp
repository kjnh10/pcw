#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
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
    string a, b;
    cin >> a >> b;

    int n = sz(a), m = sz(b);
    if(n > m){
        cout << "GREATER" << endl;
        return 0;
    }
    else if(n < m){
        cout << "LESS" << endl;
        return 0;
    }
    else
    {
        REP(i, 0, n)
        {
            if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return 0;
            }
            else if(a[i] < b[i]){
                cout << "LESS" << endl;
                return 0;
            }
        }
    }

    cout << "EQUAL" << endl;

	return 0;
}