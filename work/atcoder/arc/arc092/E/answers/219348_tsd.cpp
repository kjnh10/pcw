#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll s = 0;
    ll t = 0;
    vector<int> x,y;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(a[i]>=0){
                x.push_back(i);
                s += a[i];
            }
        }else{
            if(a[i]>=0){
                y.push_back(i);
                t += a[i];
            }
        }
    }
    if(x.size()==0&&y.size()==0){
        ll ma = -inf;
        int tmp = -1;
        rep(i,n){
            if(ma<a[i]){
                ma = a[i];
                tmp = i;
            }
        }
        cout << ma << endl;
        cout << n-1 << endl;
        for(int i=n;i>tmp+1;i--){
            cout << i << endl;
        }
        for(int i=1;i<=tmp;i++){
            cout << 1 << endl;
        }
    }else{
        if(t>s){
            x = y;
            s = t;
        }
        if(x.size()==1){
            cout << a[x[0]] << endl;
            cout << n-1 << endl;
            for(int i=n;i>x[0]+1;i--){
                cout << i << endl;
            }
            for(int i=1;i<=x[0];i++){
                cout << 1 << endl;
            }
        }else{
            cout << s << endl;
            int tmp = x[0] + n-x[x.size()-1]-1;
            cout << tmp + (n-tmp)/2 << endl;
            for(int i=n;i>x[x.size()-1]+1;i--){
                cout << i << endl;
            }
            for(int i=0;i<x[0];i++){
                cout << 1 << endl;
            }
            for(int i=1;i<x.size();i++){
                int k = x[i]-x[i-1];
                k /=2;
                for(int j=0;j<k-1;j++){
                    cout << 3 << endl;
                }
                cout << 2 << endl;
            }
        }
    }
    return 0;
}