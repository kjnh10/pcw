#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;

//const long long DIGIT = 10000000000000LL;

int main(){
    double n, k;
    cin >> n >> k;

    //中央値1回
    double a = 1, b;
    b = n * n * n;

    //中央値2回
    if(k != 1 && k != n){
        a += (k - 1) * (n - k) * 6;
    }

    //中央値3回
    a += (n - 1) * 3;

    //show(a) show(b)

    cout <<fixed << setprecision(11) <<   a / b << endl;
}
