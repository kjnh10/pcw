#include <bits/stdc++.h>

using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	int color[N];
	for (int i = 0; i < N; i++) {
		cin >> color[i];
	}
	int ans[H][W];
	int cur = 0;
	for (int i = 0; i < H; i++) {
		if (i%2==0) {
			for (int j = 0; j < W; j++) {
				ans[i][j] = cur+1;
				color[cur]--;
				if (color[cur] == 0) cur++;
			}
		}
		else {
			for (int j = W-1; j >=0; j--) {
				ans[i][j] = cur+1;
				color[cur]--;
				if (color[cur] == 0) cur++;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (j > 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	// cin >> H;
}