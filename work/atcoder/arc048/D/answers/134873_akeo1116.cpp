#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int N;
	int hand[100001][3]={};
	int R[100001]={},H[100001]={};

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>R[i]>>H[i];
		hand[R[i]][H[i]%3]++;
	}
	for(int j=0;j<3;j++){
		for(int i=1;i<100002/*change*/;i++){
			hand[i][j]+=hand[i-1][j];
			//if(hand[i][j])
				//printf("rate=%d hand=%d == %d\n",i,j,hand[i][j]);
		}
	}

	
	for(int i=0;i<N;i++){
		cout<<hand[R[i]-1][0]+hand[R[i]-1][1]+hand[R[i]-1][2]+hand[R[i]][(H[i]+1)%3]-hand[R[i]-1][(H[i]+1)%3]<<" ";
		cout<<N-1-(hand[R[i]-1][0]+hand[R[i]-1][1]+hand[R[i]-1][2]+hand[R[i]][(H[i]+1)%3]-hand[R[i]-1][(H[i]+1)%3]+hand[R[i]][H[i]%3]-hand[R[i]-1][H[i]%3]-1)<<" ";
		cout<<hand[R[i]][H[i]%3]-hand[R[i]-1][H[i]%3]-1<<endl;
	}
	return 0;
}