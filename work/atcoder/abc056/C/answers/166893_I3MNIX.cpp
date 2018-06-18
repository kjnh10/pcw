#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int x; cin >> x;
    int n = 1;
    while (n * (n+1) / 2 < x) n++;
    cout << n << endl;
}
