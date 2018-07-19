#include <iostream>

using namespace std;

int main()
{
	const int N = 3;
	int score[N];
	int rank[N];

	for (int i = 0; i < N; i++) {
		cin >> score[i];
		rank[i] = score[i];
	}
	// 並べ替え
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (rank[j] < rank[j + 1]) {
				int tmp;
				tmp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = tmp;
			}
		}
	}
	// 順位表示
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (score[i] == rank[j]) {
				cout << j + 1 << endl;
			}
		}
	}
	return (0);
}