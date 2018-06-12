#include <iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
typedef long long int ll;
using namespace std;

int main(){
    int64_t N,K;
    int64_t ans=1;
    cin >> N >> K;
    ans=K;
    for(int n=1;n<N;n++){
        ans*=(K-1);
    }
    cout << ans << endl;
    
    return 0;
}
