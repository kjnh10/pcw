#include<bits/stdc++.h>
/*
*/

using namespace std;

typedef pair<long long int, vector<long long int>> PLVL;

int main(){
	long long int N;
	cin >> N;
	vector<long long int>A(N);
	for( size_t i = 0; i < N; i++ ){
		cin >> A[i];
	}
	auto B = A;
	sort(A.begin(), A.end());
	long long int mid = N / 2;
	long long int minv = A[mid - 1];
	long long int maxv = A[mid];
	for( size_t i = 0; i < N; i++ ){
		if( maxv > B[i] ){
			cout << maxv << endl;
		} else{
			cout << minv << endl;
		}
	}
}

