#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <utility>

using namespace std;
using pii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	int argmax = 0;
	for(int i = 1; i < n; ++i){
		if(abs(a[i]) > abs(a[argmax])){ argmax = i; }
	}
	vector<pii> solution;
	const int maxval = a[argmax];
	for(int i = 0; i < n; ++i){
		if(i == argmax){ continue; }
		solution.emplace_back(argmax, i);
	}
	if(maxval >= 0){
		for(int i = 1; i < n; ++i){ solution.emplace_back(i - 1, i); }
	}else{
		for(int i = n - 1; i > 0; --i){ solution.emplace_back(i, i - 1); }
	}
	cout << solution.size() << endl;
	for(const auto& p : solution){
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}
	return 0;
}

