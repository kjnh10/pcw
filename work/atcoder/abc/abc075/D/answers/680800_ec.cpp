#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
	int n,k;
	cin >> n >> k;

	vector<int> x(n),y(n);
	vector<int> xary,yary;

	for(int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		xary.push_back(x[i]);
		yary.push_back(y[i]);
	}
	
	sort(begin(xary),end(xary));
	sort(begin(yary),end(yary));
	
	ll ans = 1LL * (xary[n-1] - xary[0]) * (yary[n-1] - yary[0]);

	for(int xi = 0; xi < n; ++xi){
		for(int xj = xi + 1; xj < n;++xj){
			for(int yi = 0; yi < n; ++yi){
				for(int yj = yi + 1; yj < n;++yj){
	
					int num = 0;
					ll lx = xary[xi],rx = xary[xj];
					ll by = yary[yi],uy = yary[yj];

					for(int i = 0; i < n;++i){
						if(lx <= x[i] and x[i] <= rx and by <= y[i] and y[i] <= uy){
							num++;
						}
					}

					if(num >= k) ans = min(ans,1LL * (rx - lx) * (uy - by));
				}
			}
		}
	}

	cout << ans << endl;
	
	return 0;
}