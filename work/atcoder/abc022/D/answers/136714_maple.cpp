#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	double ax[100001], ay[100001], bx[100001], by[100001];
	for(int i = 0; i < n; i++){
		cin >> ax[i] >> ay[i];
	}
	for(int i = 0; i < n; i++){
		cin >> bx[i] >> by[i];
	}
	double centerax = 0.0, centeray = 0.0, centerbx = 0.0, centerby = 0.0;
	for(int i = 0; i < n; i++){
		centerax += ax[i];
		centeray += ay[i];
		centerbx += bx[i];
		centerby += by[i];
	}
	centerax /= n;
	centeray /= n;
	centerbx /= n;
	centerby /= n;
	double maxlena = 0.0, maxlenb = 0.0;
	for(int i = 0; i < n; i++){
		maxlena = max(maxlena, sqrt(pow(ax[i] - centerax, 2) + pow(ay[i] - centeray, 2)));
		maxlenb = max(maxlenb, sqrt(pow(bx[i] - centerbx, 2) + pow(by[i] - centerby, 2)));
	}
	printf("%.10f\n", maxlenb / maxlena);
	return 0;
}