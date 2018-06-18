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

	int n,k;
	cin>>n>>k;

	vector<int> d(10);
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		d[x]++;
	}

	for(int i=n;;i++){
		string s=to_string(i);
		bool ok=true;
		for(int j=0;j<s.size();j++){
			if( d[s[j]-'0'] ) ok=false;
		}
		if(ok){
			cout<<i<<endl;
			break;
		}
	}

}