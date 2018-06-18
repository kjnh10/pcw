#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;
int n,k;
int num[200006];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		num[a]++;
	}
	sort(num,num+200006,cmp);
	int ans=0;
	for (int i=k;i<n;++i){
		ans+=num[i];
	}
	cout<<ans<<endl;
	return 0;
}