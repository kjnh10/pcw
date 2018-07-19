#include<bits/stdc++.h>
using namespace std;
long long n,p[1000];
/*long long solve(vector<long long>E){
    long long cnt=0;
    while(true){
        sort(E.begin(),E.end());
        if(E[E.size()-1]<(long long)E.size())break;
        E[E.size()-1]-=E.size();
        for(int i=0;i<E.size()-1;i++)E[i]++;
        cnt++;
    }
    return cnt;
}*/
int main(){
    cin>>n;
    long long B=n/50;
    for(long long i=0;i<50;i++)p[i]=49+B;
    for(long long i=0;i<(n%50);i++){
        p[i]+=50;
        for(long long j=0;j<50;j++){if(i!=j)p[j]--;}
    }
    /*vector<long long>T;
    for(int i=0;i<50;i++)T.push_back(p[i]);
    long long Y=solve(T);if(Y!=n)cout<<"WA"<<endl; cout<<Y<<endl;*/
    cout<<50<<endl;
    for(long long i=0;i<50;i++){if(i)cout<<' ';cout<<p[i];}
    cout<<endl;
    return 0;
}