#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iterator>
#include <set>
#include <functional>

using namespace std;

#define DT int
#define forn(i,n)for(i=0;i<n;i++)
#define forc(i,c,n)for(i=c;i<=n;i++)
#define all(x) (x).begin(), (x).end()


int main() {
	ifstream fin("Text.txt");
	DT i, j, q;
	DT a=-1, b, n, m,x;
	string st;
	cin >> st;
	x = st.size();
	forn(i, st.size()) {
		if (st[i] == 'A' && a == -1)
			a = i;
		if (st[i] == 'Z')
			b = i;
	}
	cout << b - a + 1 << endl;
	return 0;
}