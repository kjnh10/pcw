#include<bits/stdc++.h>
/*
*/

using namespace std;

typedef pair<long long int, vector<long long int>> PLVL;

int main(){
	long long int N, M, X;
	cin >> N >> M >> X;
	vector<long long int>D(M);
	long long int ans = M;
	for( size_t i = 0; i < M; i++ ){
		cin >> D[i];
		if( D[i] > X ){
			ans = i;
			break;
		}
	}
	cout << min(ans, M - ans) << endl;
}

