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
#include <bits/stdc++.h>
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

bool ok[1005];
int main(int argc,char* argv[]){
	for(int i=1;i<=50;i++){
		int ex=i;
		for(int j=2;j<=1000;j++){
			ex*=i;
			if(ex>1000){
				break;
			}else{
				ok[ex]=true;
			}
		}
	}
	
	int x;
	cin>>x;
	
	while(!ok[x]){
		x--;
	}
	cout<<x;
	return 0;
}
