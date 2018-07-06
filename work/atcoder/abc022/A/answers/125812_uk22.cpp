#include <stdio.h>
#include <iostream>


using namespace std;

int main(){

    int N;
    int S;
    int T;
    int sum = 0;
    int count = 0;
    
    cin >> N;
    cin >> S;
    cin >> T;
    int A[N];

    for(int i=0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        if( S <= sum && sum <= T)
            count++;
    }
    
    cout << count << endl;
    
    return 0;

}
