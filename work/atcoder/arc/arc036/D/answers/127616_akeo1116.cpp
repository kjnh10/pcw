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
	int h[300001];
	bool val[300001]={};
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>h[i];
	}
	val[0]=1;
	val[N-1]=1;
	for(int i=1;i<N-1;i++){
		if(h[i-1]>h[i] && h[i]<h[i+1])
			val[i]=1;
	}
	int pre=0;
	int maxi=0;
	for(int i=0;i<N;i++){
		if(val[i]){
			//cout<<"pre="<<pre<<endl;
			maxi=max(maxi,i-pre+1);
			pre=i;
		}
	}
	cout<<maxi<<endl;
	return 0;
}