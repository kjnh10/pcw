#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<int> r[11];
int lv[11] = { 0,0,0,0,0,0,0,0,0,0,0 };

void serch(int f) {
	for (int i = 1; i <= n; i++) {
		if (lv[i] == f) {
			for (int j = 0; j < r[i].size(); j++) {
				if (lv[r[i][j]]==0)lv[r[i][j]] = f + 1;
			}
		}
	}
}

int solve(int lv[]) {
	for (int i = 1; i <= 2; i++) serch(i);

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (lv[i] == 3)res++;
	}
	/*for (int i = 1; i <= n; i++)cout << lv[i];
	cout << endl;*/
	return res;
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		r[a].push_back(b);
		r[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 11; j++)lv[j] = 0;
		lv[i] = 1;
		cout << solve(lv) << endl;
	}

	return 0;
}