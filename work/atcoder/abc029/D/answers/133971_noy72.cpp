#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long k = 10;
    long long ans = 0;
    rep(i,9){
        ans += n / k * (k / 10LL);
        ans += min(max(0LL, n % k - (k / 10LL - 1)), k / 10LL);
        k*=10LL;
    }
    cout << ans << endl;
}
