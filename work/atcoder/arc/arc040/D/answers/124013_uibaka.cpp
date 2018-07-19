#include <iostream>
#include <string>
#include <cmath>
using ll = long long;
using namespace std;

int main() {
    int N, R;
    cin >> N >> R;
    string S;
    cin >> S;
    int res = max(0, (int)S.rfind('.') - R + 1);
    int prev = -1;
    for(int i=S.size()-1; i>=0; --i) {
        if(S[i] == '.' && (prev == -1 || prev - i + 1 > R)) {
            res++;
            prev = i;
        }
    }
    cout << res << endl;
}
