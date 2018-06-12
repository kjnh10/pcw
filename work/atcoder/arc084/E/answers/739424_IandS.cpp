#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 300010;
int K,N;
int ans[MC];

int main(){
	cin >> K >> N;
	if(K%2==0){
		cout << K/2;
		repp(i,1,N) cout << ' ' << K;
		cout << endl;
	} else {
		fill(ans,ans+N,(K+1)/2);
		int z = N-1;
		repp(i,0,N/2){
			if(ans[z] > 0){
				--ans[z];
			} else {
				--ans[z-1];
				ans[z] = K;
				if(ans[z-1]==0) --z;
				else z = N-1;
			}
		}
		repp(i,0,N){
			cout << ans[i] << (ans[i+1]==0?'\n':' ');
			if(ans[i+1]==0) break;
		}
	}
	return 0;
}
