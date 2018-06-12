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
	int N,M;
	int a[502][502]={};
	int b[502][502]={};
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d",&b[i][j]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			int temp=0;
			if(b[i][j]){
				temp=b[i][j];
				a[i+1][j]+=temp;
				for(int k=0;k<4;k++)
					b[i+dx[k]+1][j+dy[k]]-=temp;
			}

		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}