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

int a,b,c,d; 
int main(int argc,char* argv[]){
	cin>>a>>b>>c>>d;
	if(abs(c-a)<=d){
		cout<<"Yes";
		return 0;
	}
	if(abs(b-a)<=d && abs(b-c)<=d){
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
}
