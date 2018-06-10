/* ***********************************************
Author        :axp
Created Time  :2016/9/11 20:08:36
TASK		  :B.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long ll;
const int inf = 1<<30;
const int md = 1e9+7;
int n[3];
string s[3];
int T;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(int i=0;i<3;i++)cin>>s[i];
	int now=0;
	for(;;)
	{
		if(n[now]==s[now].size())
		{
			putchar('A'+now);
			putchar(10);
			return 0;
		}
		now=s[now][n[now]++]-'a';
	}
    return 0;
}
