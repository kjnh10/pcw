#include<bits/stdc++.h>
using namespace std;

typedef long long int Long;
typedef long double Double;
const int MAXN = 55;

int n, a[MAXN],
	mxP = -1, mxN = -1,
	isP = 0, isN = 0;
vector<pair<int, int>> v;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		if(a[i] > 0) {
			isP = 1;
			if(mxP == -1) mxP = i;
			else if(a[i] > a[mxP]) mxP = i;
		} else if(a[i] < 0) {
			isN = 1;
			if(mxN == -1) mxN = i;
			else if(a[i] < a[mxN]) mxN = i;
		}
	}

	if(isP && isN) {
		if(a[mxP] > -a[mxN]) {
			for(int i = 0; i < n; ++i)
				if(i != mxP)
					v.emplace_back(mxP + 1, i + 1);
			for(int i = 0; i + 1 < n; ++i)
				v.emplace_back(i + 1, i + 2);
		} else {
			for(int i = 0; i < n; ++i)
				if(i != mxN)
					v.emplace_back(mxN + 1, i + 1);
			for(int i = n - 1; i > 0; --i)
				v.emplace_back(i + 1, i);
		}
	} else if(isP) {
		for(int i = 0; i + 1 < n; ++i)
			v.emplace_back(i + 1, i + 2);
	} else if(isN) {
		for(int i = n - 1; i > 0; --i)
			v.emplace_back(i + 1, i);
	}

	printf("%d\n", (int) v.size());
	for(auto &p : v)
		printf("%d %d\n", p.first, p.second);

	return 0;
}
