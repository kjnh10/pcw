#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

int main(){
	int N, L;
	while(cin >> N >> L){
		deque< pair<double, double> > dq;
		int t, v; cin >> t >> v;
		dq.push_back(make_pair(t, v));
		printf("%.8lf\n", (double)t);
		double sumT = t * (double)v;
		for(int i=1;i<N;i++){
			cin >> t >> v;
			double sub = v;
			for(int j=0;j<dq.size();j++){
				if(dq[j].second <= sub){
					sumT -= dq[j].first * dq[j].second;
					sub -= dq[j].second;
					dq[j].second = 0;
				} else {
					sumT -= dq[j].first * sub;
					dq[j].second -= sub;
					break;
				}
			}
			sumT += t * (double)v;
			printf("%.8lf\n", sumT/L);
			while(!dq.empty() && dq[0].second < 1e-8) dq.pop_front();
			pair<double, double> p = make_pair(t, v);
			while(!dq.empty()){
				if(dq.back().first < p.first) break;
				double nt = dq.back().first * dq.back().second + p.first * p.second;
				double nv = dq.back().second + p.second;
				p.first = nt/nv;
				p.second = nv;
				dq.pop_back();
			}
			dq.push_back(p);
		}
	}
}

