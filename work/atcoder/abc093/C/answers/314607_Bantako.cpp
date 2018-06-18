#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int A[3];
    cin >> A[0] >> A[1] >> A[2];

    int cnt = 0;
    sort(A,A+3);
    int maxi = A[2];
    A[0] = maxi - A[0];
    A[1] = maxi - A[1];
    cnt += A[0]/2 + A[1]/2;
    A[0] %= 2;A[1] %= 2;
    if(A[0] & A[1]){
        cnt += 1;
    }else if(A[0] ^ A[1]){
        cnt += 2;
    }
    cout << cnt << endl;
}