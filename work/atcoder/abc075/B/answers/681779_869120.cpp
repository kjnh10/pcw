#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<map>
using namespace std;
#pragma warning(disable: 4996)
string S[1000]; int H, W;
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++)cin >> S[i];
	int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#')cout << "#";
			else {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int cx = i + dx[k], cy = j + dy[k];
					if (cx < 0 || cx >= H || cy < 0 || cy >= W)continue;
					if (S[cx][cy] == '#')cnt++;
				}
				cout << cnt;
			}
		}
		cout << endl;
	}
	return 0;
}