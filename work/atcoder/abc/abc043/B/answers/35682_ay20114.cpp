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

	vector<char> ans;
	string s;
	cin>>s;

	for(int i=0;i<s.size();i++){
		if(s[i]=='0') ans.push_back('0');
		else if(s[i]=='1') ans.push_back('1');
		else if(!ans.empty()) ans.pop_back();
	}

	for(int i=0;i<ans.size();i++) cout<<ans[i];
	cout<<endl;

}