#include<iostream>
#include<vector>

using namespace std;

int n, m;
bool g=false;
vector<int> t[6];


void dtb(int testd,char (&testb)[7]) {
	int bit[7] = { 64,32,16,8,4,2,1 };
	for (int i = 0; i < 7; i++) {
		if (testd >= bit[i]) {
			testb[i] = 1;
			testd -= bit[i];
		}
	}
	return;
}

void bxor(char testb[], char xored[],char (&next)[7] ) {
	for (int i = 0; i < 7; i++) {
		if (testb[i] != xored[i])next[i] = 1;
		else next[i] = 0;
	}
	return;
}

bool solve(char xored[]) {
	for (int i = 0; i < 7; i++) {
		if (xored[i] == 1) {
			return false;
		}
	}
	return true;
}

void dfs(int dpth,char xored[7]) {
	if (g)return;

	char temp[7];
	for (int i = 0; i < 7; i++)temp[i] = xored[i];

	for (int i = 0; i < t[dpth].size(); i++) {
		for (int j = 0; j < 7; j++)xored[j] = temp[j];
		char testb[7] = { 0,0,0,0,0,0,0 };
		char next[7] = { 0,0,0,0,0,0,0 };

		dtb(t[dpth][i], testb);
		bxor (testb, xored, next);

		if (dpth == n) {

			if (solve(next)==true) {
				g = true;
				return;
			}
		}
		else {
			dfs(dpth + 1, next);
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			t[i].push_back(a);
		}
	}

	char xorb[7] = { 0,0,0,0,0,0,0 };
	dfs(1, xorb);

	if (g)cout << "Found" << endl;
	else cout << "Nothing" << endl;
	

	return 0;
}