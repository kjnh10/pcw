#include <iostream>
#include <algorithm>
using namespace std;

bool friends[11][11] = {};
bool flg [11][11] = {};

int main(){
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		friends[a][b] = true;
		friends[b][a] = true;
	}
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == j) continue;
			if (friends[i][j]){
				for (int k = 1; k <= N; k++){
					if (j == k&&i==k) continue;
					if (friends[j][k] && friends[i][k] == false) flg[i][k]=true;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++){
		int tmp = 0;
		for (int j = 1; j <= N; j++){
			if (i == j) continue;
			if (flg[i][j]) tmp++;
		}
		cout << tmp << endl;
	}

	return 0;
}