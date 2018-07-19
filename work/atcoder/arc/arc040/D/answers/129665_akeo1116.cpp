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
	int N,R;
	char S[101];
	cin>>N>>R;
	cin>>S;
	int tes=0,ket=0;
	for(int i=0;i<N;i++)
		if(S[i]=='.')
			tes=i;
	ket+=max(0,tes+1-R);
	for(int i=0;i<N;i++){
		if(S[i]=='.'){
			i+=R-1;
			ket++;

		}
	}
	cout<<ket<<endl;
	return 0;
}