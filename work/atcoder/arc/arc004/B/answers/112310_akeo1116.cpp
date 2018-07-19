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
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int N,d[500]={};
	int maxi=-1,sum=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>d[i];
		maxi=max(maxi,d[i]);
		sum+=d[i];
	}
	cout<<sum<<endl;
	if(maxi<sum-maxi)
		cout<<0<<endl;
	else
		cout<<maxi-(sum-maxi)<<endl;
	return 0;
}