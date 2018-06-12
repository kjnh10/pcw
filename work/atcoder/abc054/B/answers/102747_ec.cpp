#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
	int N,M;
	cin >> N >> M;

	const int nmmax=50;
	char A[nmmax][nmmax],B[nmmax][nmmax];


	for(int y=0;y<N;++y){
		for(int x=0;x<N;++x){
			cin >> A[y][x];
		}
	}

	for(int y=0;y<M;++y){
		for(int x=0;x<M;++x){
			cin >> B[y][x];
		}
	}

	bool exist=false;
	
	for(int ly=0;ly<N;++ly){
		for(int lx=0;lx<N;++lx){
			if(ly+M-1>=N or lx+M-1>=N) continue;

			bool match=true;
			for(int y=0;y<M;++y){
				for(int x=0;x<M;++x){
					if(A[ly+y][lx+x]!=B[y][x]) match=false;
				}
			}
			if(match) exist=true;
		}
	}

	if(exist)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}