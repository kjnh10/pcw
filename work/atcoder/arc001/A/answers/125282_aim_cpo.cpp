/*  .　　∧_∧
   　（ ´・ω・)
   　//＼￣￣旦＼
   ／/ ※ ＼＿＿＿＼
   ＼＼ 　※ 　※ 　※ ヽ
   　 ＼ヽ-＿_＿--＿__ヽ*/

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a); i<(b); i++)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define sort(v,n) sort(v,v+n);
#define vsort(v) sort(v.begin(),v.end());
#define vvsort(v) sort(v.begin(),v.end(),greater<int>());
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
typedef pair<int,int> p;
typedef pair<ll,ll> lp;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > rpq;
bool is_uruu(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}
const ll MOD=1e9+7;
const double PI=acos(-1.0);
//-------------------------------------------------------------------------------------------------------------------------------------------//
int a=0,b=0,c=0,d=0;
int main(){
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0; i<n; i++) {
                if(s.substr(i,1)=="1") {
                        a++;
                }else if(s.substr(i,1)=="2") {
                        b++;
                }else if(s.substr(i,1)=="3") {
                        c++;
                }else {
                        d++;
                }
        }
        cout<<max(a,max(b,max(c,d)))<<" "<<min(a,min(b,min(c,d)))<<endl;
}
