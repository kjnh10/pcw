#include <iostream>
#include <vector>

#define rep(a, b) for(int a  = 0; a < b; a++)
#define repr(a, b) for(int a = b; a >= 0; a++)

using namespace std;

int main(){
    int A, B;
    char op;
    cin >> A >> op >> B;
    if (op == '+') {
        cout << A + B << endl;
    } else {
        cout << A - B << endl;
    }
    return 0;
}