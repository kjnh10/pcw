#include<bits/stdc++.h>
using namespace std;
#define ran 100010
int n,res,W;
vector<int> e[ran];
int sz[ran];
void dfs1(int x,int fat){
	int cnt = 0;
	sz[x] = 0;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		dfs1(y, x);
		cnt ++;
		sz[x] += sz[y];
	}
	sz[x] += cnt / 2;
	if(x == fat)sz[x] += cnt % 2;
}
bool dfs(int x,int fat){
	vector<int> e;
	for(vector<int>::iterator it = ::e[x].begin(); it != ::e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		if(!dfs(y, x))return false;
		e.push_back(sz[y] + 1);
	}
	if(x == fat){
		if(e.size() % 2)e.push_back(0);
		sort(e.begin(), e.end());
		int L = e.size();
		for(int i=0,j=L-1; i<j; i++,j--)
			if(e[i] + e[j] > W)
				return false;
		return true;
	}
	if(e.size() % 2 == 0)e.push_back(0);
	sort(e.begin(), e.end());
	int L = e.size();
	int lo = 0, hi = L;
	while(lo != hi){
		int mi = (lo + hi)/2;
		bool flag = true;
		for(int i=0,j=L-1;;){
			if(i==mi)i++;
			if(j==mi)j--;
			if(i>j)break;
			if(e[i] + e[j] > W){
				flag = false;
				break;
			}
			i++;j--;
		}
		if(flag)
			hi = mi;
		else
			lo = mi+1;
	}
	if(hi == L)return false;
	sz[x] = e[lo];
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,1);
	printf("%d ",sz[1]);
	int lo = 1, hi = n-1;
	while(lo != hi){
		W = (lo + hi)/2;
		if(dfs(1, 1))
			hi = W;
		else
			lo = W+1;
	}
	printf("%d\n",lo);
	return 0;
}
