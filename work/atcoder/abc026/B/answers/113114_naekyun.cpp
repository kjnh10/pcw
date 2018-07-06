#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    vector<int> r;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        r.push_back(input);
    }
    sort(r.begin(), r.end(), greater<int>());
    
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            total += (double)3.1415926535*r[i]*r[i];
        } else {
            total -= (double)3.1415926535*r[i]*r[i];
        }
    }

    cout << fixed << setprecision(7) << total << endl;

    return 0;
}
