#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX=1e5;

int main(){
	int Q;
	cin>>Q;
	lli A[100],B[100];
	rep(i,Q){
		cin>>A[i]>>B[i];
		if(A[i]==B[i])cout<<2*A[i]-2<<endl;
		else if(abs(A[i]-B[i])==1)cout<<2*min(A[i],B[i])-2<<endl;
		else{
			lli sq=sqrt(A[i]*B[i]);
			if(A[i]*B[i]==sq*sq)cout<<2*sq-3<<endl;
			else if(sq*(sq+1)>=A[i]*B[i])cout<<2*sq-2<<endl;
			else cout<<2*sq-1<<endl;
		}
	}
}