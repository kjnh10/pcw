#include <bits/stdc++.h>

#define maxn 100000008
#define pp push_back
#define pf push_front
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int a[55][55];

int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char s[55];
		scanf("%s", s);
		for (int j = 0; j < strlen(s); ++j) {
			a[i][s[j]-'a']++;
		}
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		int foo = 123;
		for (int i = 0; i < n; ++i) {
			foo = min(foo, a[i][c-'a']);
		}
		for (int i = 0; i < foo; ++i) {
			printf("%c", c);
		}
	}
	return 0;
}
