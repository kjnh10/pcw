#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdio>
#define fol(i,n) for(int i=0;i<n;i++)
#define db(a) cout << a<< endl;
using namespace std;


int main(){
    string s;
    cin >>s;
    cout << s[0]<<s.size()-2<<s[s.size()-1]<<endl;
    return 0;
}
