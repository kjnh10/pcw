#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <cmath>
#include <string> // これがないとstringの出力がエラー
#include <sstream>
#include <algorithm>

using namespace std;

void pA()
{
}

void pB()
{
	bool okay[100000];
	for (int i = 0; i < 100000; ++i)
		okay[i] = false;

	int cnt = 0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int t;
		cin >> t;
		if (okay[t-1])
			cnt++;
		okay[t-1] = true;
	}

	cout << cnt << endl;
}

void pC()
{
	int N, K;
	cin >> N >> K;
	cin.ignore();
	string str;
	getline(cin, str);
	stringstream ss(str);
	vector<int> data(N);
	for (int i = 0; i < N; ++i) {
		ss >> data[i];
	}

	sort(data.begin(), data.end());

	double current = 0;
	for (int i = N - K; i < N; ++i) {
		current = (current + (double)data[i]) / 2.0;
		cerr << data[i] << endl;
	}

	cout << fixed << setprecision(7) << current << endl;
}

int main()
{
	pB();

	return 0;
}