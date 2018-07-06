
#include <stdio.h>
#include <iostream>


using namespace std;

int main(){

    int N;
    int count = 0;
    
    cin >> N;
    int A[N];
    int B[100001] = {0};

    for(int i=0; i < N; i++)
    {
        cin >> A[i];
        B[ A[i] ]++;
        if( B[ A[i] ] > 1)
            count++;
    }
    
    cout << count << endl;
    
    return 0;

}
