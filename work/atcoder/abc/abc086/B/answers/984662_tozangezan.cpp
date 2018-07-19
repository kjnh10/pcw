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
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
char str[110];
char A[10];
char B[10];
int main(){
	scanf("%s%s",A,B);
	sprintf(str,"%s%s",A,B);
	int c;sscanf(str,"%d",&c);
	for(int i=0;i<1100;i++){
		if(i*i==c){
			printf("Yes\n");return 0;
		}
	}
	printf("No\n");
}