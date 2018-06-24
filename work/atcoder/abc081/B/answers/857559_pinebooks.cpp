#include <iostream>

#define INF 1000000000

using namespace std;

int main() {
    int N;
    cin >> N;

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        int res = 0;
        while (A % 2 == 0) {
            res++;
            A /= 2;
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
}