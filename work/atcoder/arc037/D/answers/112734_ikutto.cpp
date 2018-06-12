#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex,vector<vector<int>> &edge,vector<int> &visited,vector<int> &v){
	visited[vertex]=1;
	v.push_back(vertex);
	for(int i=0;i<edge[vertex].size();i++){
		int to=edge[vertex][i];
		if(!visited[to]){
			dfs(to,edge,visited,v);
		}
	}
	return;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> edge(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--,v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	vector<int> visited(n,0);
	vector<vector<int>> connected;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> v;
			dfs(i,edge,visited,v);
			connected.push_back(v);
		}
	}
	int res=0;
	for(int i=0;i<connected.size();i++){
		int edge_num=0;
		for(int j=0;j<connected[i].size();j++){
			edge_num+=edge[connected[i][j]].size();
		}
		edge_num/=2;
		if(edge_num+1==connected[i].size()){
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
