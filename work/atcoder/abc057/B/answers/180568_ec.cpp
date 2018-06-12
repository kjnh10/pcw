#include <bits/stdc++.h>
using namespace std;
int main(void){
	int N,M;
	cin >> N >> M;

	const int NMMAX=50;
	int A[NMMAX],B[NMMAX],C[NMMAX],D[NMMAX];

	for(int i=0;i<N;++i){
		cin >> A[i] >> B[i];
	}

	for(int j=0;j<M;++j){
		cin >> C[j] >> D[j];
	}
	
	for(int i=0;i<N;++i){
		int min_dist=abs(A[i]-C[0])+abs(B[i]-D[0]),checkpoint=1;

		for(int j=1;j<M;++j){
			const int cur_dist=abs(A[i]-C[j])+abs(B[i]-D[j]);
			if(min_dist>cur_dist){
				min_dist=cur_dist;
				checkpoint=j+1;
			}
		}

		cout << checkpoint << endl;
	}
	
	return 0;
}