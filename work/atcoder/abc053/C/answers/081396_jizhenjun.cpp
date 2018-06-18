#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <cctype>
#include <climits>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <iterator>
#include <algorithm>
#include <stack>
#define _clr(x,y) memset(x,y,sizeof(x))
#define _inf(x) memset(x,0x3f,sizeof(x))
#define pb push_back
#define mp make_pair
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
typedef long long LL;
const int maxn=1000000+5;
int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);
	#ifndef ONLINE_JUDGE
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	
	LL x,ans=0;
	cin>>x;ans=x/11*2;
	if(x%11!=0)
	{
		ans++;
		if(x%11>6) ans++;
	}
	cout<<ans;
	
    return 0;
}
