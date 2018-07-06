
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>

using namespace std;

#define rep(i,n,m) for(int i=n;i<(int)(m);i++)

int main() {

	int n;
	cin >> n;
	vector<int>c(1000002, 0);
	vector<int>a(n,0);
	vector<int>b(n,0);
	
	rep(i, 0, n) {
		cin >> a[i] >> b[i];
		c[a[i]] += 1;
		c[b[i]+1] -= 1;
	}

	

	rep(i, 1, 1000001) {
		c[i] += c[i - 1];
	}

	int ans = -1;

	rep(i, 0, 1000001) {
		ans=max(c[i],ans);
	}

 	cout << ans << endl;


	return 0;
}
