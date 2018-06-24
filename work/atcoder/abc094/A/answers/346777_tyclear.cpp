#include <map>
#include <list>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int a,b,c;
int main()
{
	fast; 
	cin>>a>>b>>c;
	if (a>c || a+b<c)
	   cout<<"NO"<<endl;
	else
	   cout<<"YES";
    return 0;
}