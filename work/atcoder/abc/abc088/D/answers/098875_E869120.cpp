#include <iostream>
#include <queue>
#include <string>
using namespace std;

int H, W, dist[59][59], sum; string S[59];

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> S[i];
		for (int j = 0; j < W; j++) { if (S[i][j] == '.') sum++; }
	}
	for (int i = 0; i < 59; i++) { for (int j = 0; j < 59; j++) dist[i][j] = (1 << 30); }
	queue<pair<int, int>>Q; Q.push(make_pair(0, 0)); dist[0][0] = 1;
	while (!Q.empty()) {
		int a1 = Q.front().first, a2 = Q.front().second; Q.pop();
		int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; i++) {
			int cx = a1 + dx[i], cy = a2 + dy[i];
			if (cx < 0 || cy < 0 || cx >= H || cy >= W || dist[cx][cy] <= dist[a1][a2] + 1 || S[cx][cy] == '#') continue;
			Q.push(make_pair(cx, cy));
			dist[cx][cy] = dist[a1][a2] + 1;
		}
	}
	if (dist[H - 1][W - 1] == (1 << 30)) cout << "-1" << endl;
	else cout << sum - dist[H - 1][W - 1] << endl;
	return 0;
}