#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;


long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>v(H);
	for (int i = 0; i < H; i++) {
		cin >> v[i];
	}
	int dir[] = { 0,1,0,-1,0 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (v[i][j] == '.') {
				continue;
			}
			bool flag = false;
			for (int k = 0; k < 4; k++) {
				int ny = i + dir[k];
				int nx = j + dir[k + 1];
				if (ny < 0 || nx < 0 || ny >= H || nx >= W) {
					continue;
				}
				if (v[ny][nx] == '#') {
					flag = true;
				}
			}
			if (!flag) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}
