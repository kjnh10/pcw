#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	if(str[n-1]==str[0])
	{
		if(n%2==1) puts("Second");
		else puts("First");
	}
	else
	{
		if(n%2==1) puts("First");
		else puts("Second");
	}
	return 0;
}
