#include <iostream> 
#include <string> 
#include <vector> 
#include <cmath> 
#include <algorithm> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 
#include <functional> 
#include <set> 
#include <sstream> 
#include <cctype>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <list>
#include <cassert>
 
using namespace std; 


int main(){

	int n,k,x,y;
	cin>>n>>k>>x>>y;

	int res=0;
	for(int i=0;i<n;i++){
		if(i<k) res+=x;
		else res+=y;
	}

	cout<<res<<endl;

}