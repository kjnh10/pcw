#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int a,b;
	char c;
	cin>>a>>c>>b;
	if(c=='+')cout<<a+b<<endl;
	else cout<<a-b<<endl;
	return 0;
}