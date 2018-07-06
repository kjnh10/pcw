#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
#define PI 3.14159265359
using namespace std;

int main()
{
	double x;
	cin >> x;
	double y = x / 2;

	int z = (int)pow(y, 2);

	cout << z << endl;

	return 0;
}