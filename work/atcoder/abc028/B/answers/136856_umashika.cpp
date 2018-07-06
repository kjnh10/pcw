#include <bits/stdc++.h>
using namespace std;
#define SPACE " "
int main()
{
    string s;
    cin>>s;
    cout<<count(s.begin(),s.end(),'A')<<SPACE; 
    cout<<count(s.begin(),s.end(),'B')<<SPACE;
    cout<<count(s.begin(),s.end(),'C')<<SPACE;
    cout<<count(s.begin(),s.end(),'D')<<SPACE;
    cout<<count(s.begin(),s.end(),'E')<<SPACE;
    cout<<count(s.begin(),s.end(),'F')<<endl;
    return 0;
}