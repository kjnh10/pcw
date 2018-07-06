#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back

const ll M = 1'000'000'007;

int k;

void nxt(vector<int>& in, vector<int>& out){
	out.resize(k, 0);
	out[0]=in[k-1];
	for(int i=1; i<k; ++i){
		out[i]=(in[i-1]+in[k-1])%M;
	}
}

vector<int> twice(vector<int> v){
	vector<vector<int>> base(k);
	base[0] = v;
	for(int i=1; i<k; ++i) nxt(base[i-1], base[i]);
	vector<int> ret(k, 0);
	for(int i=0; i<k; ++i){
		int coe=v[i];
		for(int j=0; j<k; ++j){
			ret[j] = (ret[j] + base[i][j]*1LL*coe)%M;
		}
	}
	return ret;
}

vector<int> get(int n){
	if(n < k){
		vector<int> ret(k);
		ret[n]=1;
		return ret;
	}
	vector<int> ret = twice(get(n/2));
	if(n&1){
		vector<int> tmp;
		nxt(ret, tmp);
		swap(ret, tmp);
	}
	return ret;
}

int main()
{
    int n;
    read(k, n);
    --n;
    auto ans = get(n);
    cout << accumulate(all(ans), 0LL)%M << endl;
    return 0;
}
