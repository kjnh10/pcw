#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
static const double INF = 1e20;

int main(){
	ios_base::sync_with_stdio(false);
	cout << setiosflags(ios::fixed) << setprecision(10);
	int n;
	cin >> n;
	vector<double> x(n), y(n), c(n);
	for(int i = 0; i < n; ++i){ cin >> x[i] >> y[i] >> c[i]; }
	double l = 0.0, r = INF;
	for(int iter = 0; iter <= 1000; ++iter){
		const auto t = (l + r) * 0.5;
		double x0 = -INF, x1 = INF;
		double y0 = -INF, y1 = INF;
		for(int i = 0; i < n; ++i){
			x0 = max(x0, x[i] - t / c[i]);
			x1 = min(x1, x[i] + t / c[i]);
			y0 = max(y0, y[i] - t / c[i]);
			y1 = min(y1, y[i] + t / c[i]);
		}
		if(x0 < x1 && y0 < y1){
			r = t;
		}else{
			l = t;
		}
	}
	cout << l << endl;
	return 0;
}
