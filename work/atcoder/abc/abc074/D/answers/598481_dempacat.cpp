#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(n*n);

    unsigned long long int total = 0;

    for(int i=0;i<n*n;i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            bool flag = false;
            for(int k=0;k<n;k++) {
                if(i==k || j==k) continue;
                int t = v[i * n + j] - v[i * n + k] - v[k * n + j];
                if (t > 0) {
                    cout << -1 << endl;
                    return 0;
                }
                else if(t == 0) {
                    flag = true;
                }
            }
            if (!flag) total += v[i * n + j];
        }
    }
    cout << total << endl;
}
