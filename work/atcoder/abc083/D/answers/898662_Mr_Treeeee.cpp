#include <set>
#include <map>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define  LL long long
const double pi = acos(-1);
const double g = -9.8;
const int maxn = 1e5+555;

int main()
{
	char s[maxn];
	scanf("%s",s);
	int ll=strlen(s);
	int ans=ll/2;
	int l,r;
	while(1){
		l=ll-ans;
		r=ans+1;
		int flag=1;
		int now=s[l-1];
		for(int i=l;i<r;i++){
			if(s[i]!=now){
				flag=0;
				break;
			}
		}
		if(!flag){
			break;
		}
		ans++;
	}
	printf("%d\n",ans);
}

