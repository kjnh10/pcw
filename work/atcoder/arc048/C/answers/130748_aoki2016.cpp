#include<iostream>
#include<deque>
#include<algorithm>
#include<functional>
#include<string>
#include<unordered_map>
#include<map>
#include<cstdio>
#include<set>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a < 0)a++;
	if (b < 0)b++;
	cout << b - a << endl;
}