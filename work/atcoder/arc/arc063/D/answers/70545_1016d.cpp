#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 100050;
int A[MAXN];

int main() {
	int N, T;
	scanf("%d%d", &N, &T);
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	int big=A[N-1];
	int bst=0, cnt=0;
	for(int i=N-2;i>=0;i--) {
		if(big-A[i]>bst)
			bst=big-A[i], cnt=1;
		else if(big-A[i]==bst)
			cnt++;
		big=max(big, A[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
