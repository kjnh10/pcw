#include <bits/stdc++.h>

using namespace std;

const int n = 8;

bool putQueen(int h, int w, vector<string>& c) {
	c[h][w] = 'Q';
	for (int i = 0; i < n; i++) {
		if (i == w) continue;
		if (c[h][i] == 'Q') return false;
		c[h][i] = '.';
	}
	for (int i = 0; i < n; i++) {
		if (i == h) continue;
		if (c[i][w] == 'Q') return false;
		c[i][w] = '.';
	}	
	for (int i = 0; i < n; i++) {
		if (i == h) continue;
		int j = w + i - h;
		if (j < 0 || j >= n) continue;
		if (c[i][j] == 'Q') return false;
		c[i][j] = '.';
	}
	for (int j = 0; j < n; j++) {
		if (j == w) continue;
		int i = h + w - j;
		if (i < 0 || i >= n) continue;
		if (c[i][j] == 'Q') return false;
		c[i][j] = '.';
	}
	return true;
}

void printBoard(vector<string>& c) {
	for (int i = 0; i < n; i++) {
		cout << c[i] << endl;
	}
}

bool dfs(int h, int w, vector<string> c, int cnt) {
	if (!putQueen(h, w, c)) return false;
	cnt--;
	if (cnt == 0) {
		printBoard(c);
		return true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != 'o') continue;
			if (dfs(i, j, c, cnt)) return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<string> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == '.') c[i][j] = 'o';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != 'Q') continue;
			if (!putQueen(i, j, c)) {
				cout << "No Answer" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != 'o') continue;
			if (dfs(i, j, c, 5)) return 0;
		}
	}
	cout << "No Answer" << endl;
	return 0;
}