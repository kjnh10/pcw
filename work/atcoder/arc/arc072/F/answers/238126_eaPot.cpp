#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>
#include <deque>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

pair<double, double> add;
deque<pair<double, double>> en;

void PushBack(pair<double, double> x) {
	en.push_back(mp(x.fs - add.fs, x.sc - add.sc));
}

void PushFront(pair<double, double> x) {
	en.push_front(mp(x.fs - add.fs, x.sc - add.sc));
}


pair<double, double> Get(int ind) {
	pair<double, double> res = en[ind];
	res.fs += add.fs;
	res.sc += add.sc;
	return res;
}

double Temp(int ind) {
	pair<double, double> cur = en[ind];
	cur.fs += add.fs;
	cur.sc += add.sc;
	return cur.sc / cur.fs;
}

int main () {
    ios_base::sync_with_stdio(0);
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);

	int n;
	double V;
	cin >> n >> V;

	vector<double> t(n);
	vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> v[i];
	}

	
	PushBack(mp(0, 0));
	PushBack(mp(V, t[0] * V));

	vector<double> res(n);
	res[0] = Temp(sz(en) - 1);

	for (int i = 1; i < n; ++i) {
		while (Get(sz(en) - 1).fs > V - v[i] + eps) {
			if (Get(sz(en) - 2).fs > V - v[i] - eps) {
				en.pop_back();
			} else {
				pair<double, double> last = Get(sz(en) - 1);
				en.pop_back();
				pair<double, double> prev = Get(sz(en) - 1);
				PushBack(mp(V - v[i], prev.sc + (last.sc - prev.sc) / (last.fs - prev.fs) * (V - v[i] - prev.fs)));
				break;
			}
		}

		add.fs += v[i];
		add.sc += v[i] * t[i];

		while (sz(en) > 1 && Temp(1) > Temp(0) - eps) {
			en.pop_front();
		}

	    PushFront(mp(0, 0));
	    res[i] = Temp(sz(en) - 1);		
	}

	cout.precision(20);
	for (int i = 0; i < n; ++i) {
		cout << res[i] << "\n";
	}



	return 0;
}
