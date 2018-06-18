#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<tuple>
#include<queue>
#define LL long long
#define TT std::tuple<LL,LL,LL>
#define PP std::pair<LL,LL>
LL N, C;
std::vector<PP> S;
LL R[100010];
LL L[100010];
LL RS[100010];
LL LS[100010];
LL ans;
LL res;
int main() {
	std::cin >> N >> C;
	S.push_back(PP{ 0,0 });
	S.push_back(PP{ C,0 });
	for (int i = 0; i < N; i++) {
		LL x, v;
		std::cin >> x >> v;
		S.push_back(PP{ x,v });
	}
	std::sort(S.begin(), S.end());
	LL sum = 0;
	for (int i = 1; i <= N; i++) {
		RS[i] += RS[i - 1] + S[i].second;
		sum -= S[i].first - S[i-1].first;
		sum += S[i].second;
		ans = std::max(sum, ans);
		res = std::max(ans, res);
		R[i] = ans;
	}
	sum = 0;
	std::reverse(S.begin(), S.end());
	ans = 0;
	for (int i = 1; i <= N; i++) {
		LS[i] += LS[i - 1] + S[i].second;
		sum -= S[i - 1].first - S[i].first;
		sum += S[i].second;
		ans = std::max(sum, ans);
		res = std::max(ans, res);
		L[i] = ans;
	}
	std::reverse(S.begin(), S.end());
	for (int i = 1; i <= N; i++) {
		res = std::max(res, L[N - i] - S[i].first*2 + RS[i]);
	}
	std::reverse(S.begin(), S.end());
	for (int i = 1; i <= N; i++) {
		res = std::max(res, R[N - i] - (C - S[i].first)*2 + LS[i]);
	}
	std::cout << res << std::endl;
	return 0;
}