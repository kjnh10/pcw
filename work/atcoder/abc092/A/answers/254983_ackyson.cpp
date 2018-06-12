#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){
	int n,a,b,c,d;
	string str;
	cin >>  a>>b>>c>>d;
	cout <<min(a, b) + min(c, d);
}