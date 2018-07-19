#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main()
{
    set<string> ss; 
    string s;
    int k;
    cin>>s>>k;        
    REP(i,(int)s.size()-k+1){
        ss.insert(s.substr(i,k));
    }
    cout<<(int)ss.size()<<endl;
    return 0;
}