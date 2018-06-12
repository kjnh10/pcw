#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	for (int i=0;i<=100000;i ++)
		if (a*i%b==c%b) {
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}