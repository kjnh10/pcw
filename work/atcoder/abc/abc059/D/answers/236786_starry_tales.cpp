#include <bits/stdc++.h>
using namespace std;
int main() 
{
	//freopen("1.txt","w",stdout);
	long long x,y;
	scanf("%lld%lld",&x,&y);
	if(x>y) swap(x,y);
	if(x==y||(x+1==y)) printf("Brown\n");
	else printf("Alice\n");
    return 0;
}
