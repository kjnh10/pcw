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
	int num=0;
	vector<int> vec;
	int tes[300001]={};
	int s[300000]={},t[300000]={};
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>s[i]>>t[i];
		tes[s[i]]++;
		tes[t[i]+1]--;
	}
	for(int i=2;i<=N;i++){
		tes[i]+=tes[i-1];
	}
	for(int i=1;i<=N;i++){
		if(tes[i]!=1)
			tes[i]=0;
	}
	for(int i=2;i<=N;i++){
		tes[i]+=tes[i-1];
	}
	for(int i=0;i<M;i++){
		if(tes[s[i]-1]-tes[t[i]]==0){
			vec.push_back(i);
			num++;
		}
	}
	cout<<num<<endl;
	for(auto it=vec.begin();it!=vec.end();it++){
		cout<<*it+1<<endl;
	}
	return 0;
}