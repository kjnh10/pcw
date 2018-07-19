#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
using namespace std;

int n,a[200100],b[200100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=0, r=n-1, cnt=0;
	for(int i=n-1;i>=0;i--){
		if(cnt%2==0){
			b[l++] = a[i];
		}
		else{
			b[r--] = a[i];
		}
		cnt++;
	}
	for(int i=0;i<n;i++){
		if(i) cout<<" ";
		cout<<b[i];
	}
	cout<<endl;
	return 0;
}