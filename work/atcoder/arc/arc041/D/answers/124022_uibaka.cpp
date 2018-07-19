#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> v(N);
    for(int i=0; i<N; ++i) {
        cin >> v[i];
    }
    vector<string> res(N, string(M, '0'));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            int n = v[i][j] - '0';
            if(n > 0) {
                res[i+1][j] += n;
                v[i][j] -= n;
                v[i+1][j+1] -= n;
                v[i+1][j-1] -= n;
                v[i+2][j] -= n;
            }
        }
    }
    for(auto& x : res) {
        cout << x << endl;
    }
}
