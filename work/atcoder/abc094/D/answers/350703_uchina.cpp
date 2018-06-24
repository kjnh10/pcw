#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//typedef pair<int,int> P;



int main(){
	int n;
	long long a[100000];

	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%lld", &a[i]);
	}

	sort(a,a+n);

	long long p = a[n-1];
	long long r = 0;

	if(p%2==0){
		long long p2 = a[n-1]/2;
		for(int i=0;i<n-1;i++){
			if(abs(r-p2) > abs(a[i]-p2)) r = a[i];
		}
	}else{
		double p2 = (double)a[n-1]/2;
		for(int i=0;i<n-1;i++){
			if(abs((double)r-p2) > abs((double)a[i]-p2)) r = a[i];
		}
	}

	printf("%lld %lld\n", p, r);

	return 0;
}
