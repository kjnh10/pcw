#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<queue>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;

const int MAXN = 111;
int T[MAXN];

int main() {
	int N;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i];
		sum += T[i];
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int p, x;
		cin >> p >> x;
		--p;
		int ans = sum - T[p] + x;
		cout << ans << endl;
	}
	return 0;
}
