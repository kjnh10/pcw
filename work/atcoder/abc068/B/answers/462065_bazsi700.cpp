#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <iomanip>
#include <queue>
#include <deque>
#include <sstream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <map>
#include <utility>
using namespace std;

#define s(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",&n)
#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vii vector< vector<int> >
#define PI 3.1415926535897932384626433832795

int main() {
	int n;
	cin >> n;
	int count = 0;
	int maxat = 1;
	for(int i = 1; i <= n; i++) {
		int x = i;
		int cc = 0;
		while(x%2 == 0) {
			x/= 2;
			cc++;
		}
		if(cc > count) {
			count = cc;
			maxat = i;
		}
	}
	cout << maxat;
	return 0;
}

