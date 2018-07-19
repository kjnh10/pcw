#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	
	int ans = 0;
	
	for(int i = 0;i<n-1;i++){
		if(a[i+1]-a[i]<t){
			ans+=(a[i+1]-a[i]);
		}else{
			ans+=t;
		}
	}
	ans+=t;
	cout << ans << endl;
	
	return 0;
}