#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define ll long long
#define endl "\n"
#define __ ios::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
using namespace std;

string a,b;
int n,t;

int main(){

	cin >> a >> b;
	a+=b;
	n = stoi(a);
	t = sqrt(n);
	if(t*t==n) cout << "Yes\n";
	else cout << "No\n";

}