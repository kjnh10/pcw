#include<bits/stdc++.h>
using namespace std;

int cnt[4];

int main(){
    int n;
    string str;
    cin>>n;
    cin>>str;
    for(int i=0; i<n; i++){
        int in;
        in=str[i]-'1';
        cnt[in]++;
    }
    cout<<*max_element(cnt,cnt+4)<<' '<<*min_element(cnt,cnt+4)<<endl;
    return 0;
}
