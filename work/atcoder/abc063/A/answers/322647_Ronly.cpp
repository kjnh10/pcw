#include <iostream>
#include <string>
#include <algorithm>
#define ll long long
using namespace std;

int main(void){
    ll a, b;
    cin >> a >> b;
    if(a+b >= 10){
        cout << "error" << endl;
    }else{
        cout << a+b << endl;
    }
    return 0;
}