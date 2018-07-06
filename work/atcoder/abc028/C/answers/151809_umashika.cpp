#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    set<int> s;
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    sort(a,a+5);
    do{
        //cout<<a[0]+a[1]+a[2]<<endl;
        int x = a[0]+a[1]+a[2];
        if(!s.count(x)){
            s.insert(x);
            pq.push(x);
        }
    }while(next_permutation(a,a+5));
    pq.pop();pq.pop();
    //cout<<"ans"<<endl;
    cout<<pq.top()<<endl;
    return 0;
    
}