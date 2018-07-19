#include <iostream>

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int left = A + B, right = C + D;

    if (left > right)
        cout << "Left" << endl;
    else if (left == right)
        cout << "Balanced" << endl;
    else
        cout << "Right" << endl;
}