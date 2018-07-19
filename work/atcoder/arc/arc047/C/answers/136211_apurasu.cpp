 #include<bits/stdc++.h>
 using namespace std;
#define INF 1000000000
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
typedef long long LL;
int N;
int L;
string S;
int main(){
    cin>>N>>L;
    cin>>S;
    int now=1;
    int ans=0;
    REP(i,N){
        if(S[i]=='+'){
           now++;
           if(now>L){
              now=1;
              ans++;
           }
        }else{
           now=max(1,now-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}