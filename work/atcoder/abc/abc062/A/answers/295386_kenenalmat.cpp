#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iomanip>

#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define vl vector<long long>
#define sz size()
#define x first
#define y second
#define pii pair<int, int>
#define pll pair<ll, ll>


using namespace std;

int a[20];

int main() {
	a[1] = a[3] = a[5] = a[7] = a[8] = a[10] = a[12] = 1;
	a[4] = a[6] = a[9] = a[11] = 2;
	a[2] = 3;
	int x, t;
	cin >> x >> t;
	if(a[x] == a[t]) {
		cout << "Yes";
	} else {
		cout << "No";
	}


	return 0;
}