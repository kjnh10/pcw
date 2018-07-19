#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string str;
    cin>>n;
    cin>>str;
    int c[4];
    fill(c,c+4,0);
    for(int i=0; i<str.size(); i++){
        c[str[i]-'0'-1]++;
    }
    cout<<*max_element(c,c+4)<<' '<<*min_element(c,c+4)<<endl;
    return 0;
}
