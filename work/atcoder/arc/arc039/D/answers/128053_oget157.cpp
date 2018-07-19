#include <iostream>
#define MOD 1000000007
using namespace std;

int main(){
	int n,k,comb[200][200] = {};
	cin >> n >> k;
	comb[0][0] = 1;
	for(int i = 1;i < 200;i++){
		for(int j = 0;j <= i;j++){
			if(j == 0) comb[i][j] = 1;
			else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
		}
	}
	if(n > k) cout << comb[n + k - 1][k] << endl;
	else cout << comb[n][k % n] << endl;
	return 0;
}