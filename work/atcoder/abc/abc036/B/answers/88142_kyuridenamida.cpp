// failed to generate code

#include <bits/stdc++.h>
using namespace std;

int main(){	
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	char c[51][51]={};
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			
			cin >> c[j][N-i-1];
		}
	}
	for(int i = 0 ; i < N ; i++)
		cout << c[i] << endl;
}
