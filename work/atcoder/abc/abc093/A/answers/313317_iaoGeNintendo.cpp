#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
//#include "D:\C++\test_lib_projects\testlib.h"
using namespace std;
#define ll long long
#define pii pair<int,int>

bool debug=true;
/*
   Write In New Computer
    By XiaoGeNintendo
	     gwq2017
	Type:
*/

/*
void fo(int id){
	freopen((toString(id)+".txt").c_str(),"w",stdout);
}
*/
int a;
int main(int argc,char* argv[]){
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	if(s=="abc"){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
