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

	string s;
	cin>>s;

	int cnt[26]={};
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}

	for(int i=0;i<26;i++){
		if(cnt[i]%2){
			cout<<"No"<<endl;
			return 0;
		}
	}

	cout<<"Yes"<<endl;

}