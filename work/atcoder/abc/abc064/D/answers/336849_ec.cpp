#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}

using ll = long long;
using R = long double;
const R EPS = 1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r) {return (r > EPS) - (r < -EPS);}
inline R sq(R x) {return sqrt(max(x, 0.0L));}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// Problem Specific Parameter:
string s;

inline bool check(string cur, int len) {
	const int n = cur.size();
	const int m = s.size();
	int idx = 0, depth = 0;

	rep(i, n) {
		if (cur[i] == '(')
			depth++;
		else
			depth--;

		if (depth < 0) return false;
		if (idx < m and cur[i] == s[idx]) idx++;
	}


	while (idx < m) {
		if (s[idx] == '(') {
			idx++, depth++;
			cur +=  "(";
		} else {
			if (depth == 0) cur += "(", depth++;
			idx++, depth--;
			cur +=  ")";
		}
	}

	while (depth > 0) cur += ")", depth--;

	if (idx != m) return false;
	if (depth != 0) return false;
	if (int(cur.size()) > len) return false;
	return true;
}

int main(void) {
	int dummy;
	cin >> dummy;
	
	cin >> s;

	stack<int> stk;
	for (auto &c : s) {
		if (c == ')' and !stk.empty() and stk.top() == '(') {
			stk.pop();
		} else {
			stk.push(c);
		}
	}

	const int len = s.size() + stk.size();

	string ans = "";

	rep(loop, len) {
		for (auto &add : {"(", ")"}) {
			string nxt = ans + add;
			if (check(nxt, len)) {
				ans = nxt;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}