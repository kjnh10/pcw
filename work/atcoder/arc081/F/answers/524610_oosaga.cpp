#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 2005;

int n, m;
char str[MAXN][MAXN];
int match[MAXN];
int main(){
	cin >> n >> m;
	int ans = n;
	for(int i=0; i<n; i++) scanf("%s",str[i]);
	for(int i=0; i<n; i++){
		for(int j=0; j<m-1; j++){
			if(i == 0) match[j] = 1;
			else if(i > 0 && (str[i-1][j] ^ str[i-1][j+1] ^ str[i][j] ^ str[i][j+1])) match[j] = 1;
			else match[j]++;
		}
		stack<int> stk;
		for(int j=0; j<=m-1; j++){
			while(!stk.empty() && match[stk.top()] >= match[j]){
				int l = stk.top();
				stk.pop();
				int h = j - (stk.empty() ? -1 : stk.top());
				ans = max(ans, h * match[l]);
			}
			stk.push(j);
		}
	}
	cout << ans << endl;
}

