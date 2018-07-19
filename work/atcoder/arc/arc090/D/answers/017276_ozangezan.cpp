#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int UF[110000];
int d[110000];
pair<int,int> FIND(int a){
	if(UF[a]<0)return make_pair(a,0);
	pair<int,int> par=FIND(UF[a]);
	d[a]+=par.second;
	UF[a]=par.first;
//	printf("%d: %d %d\n",a,par.first,d[a]);
	return make_pair(par.first,d[a]);
}
bool dame=false;
void UNION(int a,int b,int c){
	pair<int,int>L=FIND(a);
	pair<int,int>R=FIND(b);
	if(L.first==R.first){
		if(L.second+c!=R.second){
			dame=true;
		}
		return;
	}
	UF[R.first]=L.first;
	d[R.first]=c+L.second-R.second;
	//printf("%d %d %d\n",b,UF[b],d[b]);
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)UF[i]=-1;
 
	for(int i=0;i<b;i++){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		p--;q--;
		UNION(p,q,r);
		if(dame){
			printf("No\n");return 0;
		}
	}
	printf("Yes\n");
}