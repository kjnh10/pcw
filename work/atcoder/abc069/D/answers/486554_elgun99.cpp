#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define mod 1000000007

using namespace std;

int h, w, n, c, a[101][101];

int main() {
	cin >> h >> w;
	cin >> n;
	int x = 1, y = 1, f = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		while(c--) {
			a[x][y] = i;
			y += f;
			if (y > w) y = w, x++, f = -1;
			else if (!y) y = 1, x++, f = 1;
		}
	}
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
