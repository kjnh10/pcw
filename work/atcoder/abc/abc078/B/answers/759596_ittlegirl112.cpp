#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	long long int a, b, c, d;
	cin >> a >> b >> c;
	a -= c;
	d = a / (b + c);
	cout << d << endl;
	return 0;
}