#include <bits/stdc++.h>

using namespace std;

#define inf 1<<30
#define llong long long
#define usd unsigned
#define pqueue priority_queue
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef pair<int, int> P;
int nw[9] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
int nh[9] = {1, 0, -1, 0, 1, 1, -1, -1, 0};

int a, b, c, A[1000], B[1000], C[1000], D[1000][1000];
string s, t, r;

int main(){
	cin >> a >> b;
	cout << max(max(a-b, a+b), a*b) << endl;

	return 0;
}