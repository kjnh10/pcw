#include<bits/stdc++.h>
using namespace std;

long long int a, b;

int main(){
    scanf("%lld%lld", &a, &b);
    cout << (b - a) * (b - a + 1) / 2 - b << endl;
    return 0;
}