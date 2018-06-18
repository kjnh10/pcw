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
#include <utility>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int N;
	cin>>N;
	long long pow=1;
	for(int i=1;i<=N;i++){
		pow=pow*i%MOD;
	}
	cout<<pow<<endl;
	return 0;
}