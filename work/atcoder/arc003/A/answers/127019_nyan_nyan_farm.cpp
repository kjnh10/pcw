#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double sum=0.0;
    string str;
    cin>>n>>str;
    map<char,double> point;
    point['A']=4;point['B']=3;point['C']=2;point['D']=1;point['F']=0;
    for(int i=0; i<n; i++){
        sum+=point[str[i]];
    }
    printf("%.12f",sum/n);
    return 0;
}
