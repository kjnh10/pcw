#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pii;

template<typename T>
using pq_gt = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using pq_lt = priority_queue<T, vector<T>, less<T>>;

#define se second
#define fi first
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    long double sma = -1;
    int wa, wb;
    for(int i = 0; i <= 30; i++) {
    	for(int j = 0; j <=30; ++j) {
    		for(int k = 0; k<=100; ++k) {
    			for(int l = 0; l<=100; ++l) {
    				long double tot = 100*a*i+100*b*j+k*c+l*d;
    				long double wtot= 100*a*i+100*b*j;
    				if(wtot > 0 && tot <= f) {
    					long double temp = 100*(k*c+l*d)/wtot;
    					if(temp <=  e) {
    						if(temp > sma) {
    							sma=  temp;
    							wa = 100*a*i+100*b*j+k*c+l*d;
    							wb = k*c + l*d;
    						}
    					}
    				}
    			}
    		}
    	}
    }
    //cout<<temp<<endl;
    cout<<wa<<" "<<wb<<endl;
}