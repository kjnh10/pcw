#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m,cnt[300002] = {},s[100000],t[100000],k = 0;
	vector<int> res;
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> s[i] >> t[i];
		cnt[s[i]]++;
		cnt[t[i] + 1]--;
	}
	for(int i = 1;i <= n;i++) cnt[i] += cnt[i - 1];
	for(int i = 0;i <= n;i++) if(cnt[i] >= 2) cnt[i] = 0;
	for(int i = 1;i <= n;i++) cnt[i] += cnt[i - 1];
	for(int i = 0;i < m;i++) {
		if(cnt[t[i]] - cnt[s[i] - 1] == 0){
			k++;
			res.push_back(i + 1);
		}
	}
	cout << k << endl;
	for(int i = 0;i < res.size();i++) cout << res[i] << endl;
	return 0;
}