#include <bits/stdc++.h>

using namespace std;


int n;
#define MAX 100002

vector<int> v;
map<int, int> mp;
#define MOD 1000000007
vector<int> vv;
int main(){
	cin >> n;
	{
		int lef = 0;
		int rig = n;
		for (int i = 0; i < n; i++){
			rig--;
			vv.push_back(abs(lef - rig));
			lef++;
		}
	}
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		mp[a]++;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	sort(vv.begin(), vv.end());
	if (v == vv){
		long long int ans = 1;
		for (auto it = mp.begin(); it != mp.end(); it++){
			ans *= (long long int)(*it).second;
			ans %= MOD;
		}
		printf("%lld\n", ans);
	}
	else{
		puts("0");
	}
	return 0;
}