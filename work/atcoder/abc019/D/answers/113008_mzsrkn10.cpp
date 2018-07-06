#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int max1=0, max2=0;
    int u=1;
    for(int i=2;i<=n;++i){
        int dist;
        cout << "? " << 1 << " " << i << endl;
        cin >> dist;
        if(dist > max1){
            max1 = dist;
            u = i;
        }
    }
    for(int i=1;i<=n;++i){
        if(u == i)continue;
        int dist;
        cout << "? " << u << " " << i << endl;
        cin >> dist;
        if(dist > max2)max2 = dist;
    }
    cout << "! " << max2 << endl;

    return 0;
}
