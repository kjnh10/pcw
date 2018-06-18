#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define inf 999999999
#define mp make_pair
#define pb push_back
#define fn fill_n
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<PP, int> PPP;
typedef struct data{
	int now;
	int cost;
}data;
int nh[4] = {1, 0, -1, 0};
int nw[4] = {0, 1, 0, -1};





int main(){
	int a,b,c,d,e;
	int A[100], B[100], C[100][100];
	cin >> a >> b >> c >>d;
	cout << min(a, b) + min(c, d) << endl;
	return 0;
}