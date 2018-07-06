#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int INF=1001001001;

float W,H;
int main(){
	scanf("%d %d",&W,&H);
	bool flag=false;
	if( (W/4.00) * 3.00 == H)flag=true;
	if(flag){
		printf("4:3\n");
	}else{
		printf("16:9\n");
	}
	
	return 0;
}