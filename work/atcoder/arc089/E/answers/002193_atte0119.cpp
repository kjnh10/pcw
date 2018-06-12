#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int A,B;
int D[11][11];

vector<int>X,Y,Z;

signed main(){
    cin>>A>>B;
    for(int i=1;i<=A;i++)for(int j=1;j<=B;j++)cin>>D[i][j];

    rep(i,100){
        X.pb(i);Y.pb(i+1);Z.pb(-1);
        X.pb(i+100);Y.pb(i+1+100);Z.pb(-2);
    }
    int S=0,T=200;

    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            bool flag=false;
            for(int k=0;k<=100;k++)for(int l=0;l<=100;l++){
                if(flag)continue;
                if(k*i+l*j>D[i][j])continue;
                int m=D[i][j]-k*i-l*j;
                bool ok=true;
                for(int x=1;x<=A;x++)for(int y=1;y<=B;y++)if(k*x+l*y+m<D[x][y])ok=false;
                if(!ok)continue;
                flag=true;

                bool latte=false;
                rep(w,X.size())if(X[w]==k&&Y[w]==200-l)latte=true;
                if(!latte){X.pb(k);Y.pb(200-l);Z.pb(m);}

            }
            if(!flag){
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"Possible"<<endl;



    cout<<201<<" "<<X.size()<<endl;
    rep(i,X.size()){
        cout<<X[i]+1<<" "<<Y[i]+1<<" ";
        if(Z[i]==-1)cout<<"X"<<endl;
        else if(Z[i]==-2)cout<<"Y"<<endl;
        else cout<<Z[i]<<endl;
    }
    cout<<S+1<<" "<<T+1<<endl;
    return 0;
}
