#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:108777216")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
using namespace std;
 
int const MAX_N = 128 * 1024;
 
int main() {
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    
	int a,b,c;
	cin>>a>>b>>c;
	int x;
	cin>>x;
	int cnt= 0;
	for (int i=0; i<=a; i++)
		for (int j=0; j<=b; j++)
			for (int k=0; k<=c; k++)
				cnt += i*500+j*100+k*50 == x;
	cout<<cnt;
    return 0;
}  
