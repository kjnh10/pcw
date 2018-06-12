#include <iostream>
#include <cstdio>
using namespace std;

int dx[] = {2,1,1,0},dy[] = {0,-1,1,0};

int main(){
	int n,m,field[500][500],ans[500][500] = {};
	scanf("%d %d",&n,&m);
	getchar();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) {
			char c;
			c = getchar();
			field[i][j] = c - '0';
		}
		getchar();
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(field[i][j]){
				ans[i + 1][j] = field[i][j];
				for(int k = 0;k < 4;k++){
					field[i + dx[k]][j + dy[k]] -= field[i][j];
				}
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++) printf("%d",ans[i][j]);
		puts("");
	}
	return 0;
}