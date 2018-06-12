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

static const int MAX_SIZE = 1 << 17;
const int INF=1001001001001001001ll;
int segMin[2 * MAX_SIZE ], segAdd[2 * MAX_SIZE ];

void init(){
    memset(segMin,0,sizeof(segMin));
    memset(segAdd,0,sizeof(segAdd));
}

void add(int a, int b, int x, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return;

	if (a <= l && r <= b){
		segAdd[k] += x;
		return;
	}

	add(a, b, x, k * 2 + 1, l, (l + r) / 2);
	add(a, b, x, k * 2 + 2, (l + r) / 2, r);

	segMin[k] = min(segMin[k * 2 + 1] + segAdd[k * 2 + 1], segMin[k * 2 + 2] + segAdd[k * 2 + 2]);
}

int getMin(int a, int b, int k = 0, int l = 0, int r = MAX_SIZE)
{
	if (r <= a || b <= l) return INF;

	if (a <= l && r <= b) return (segMin[k] + segAdd[k]);

	int left = getMin(a, b, k * 2 + 1, l, (l + r) / 2);
	int right = getMin(a, b, k * 2 + 2, (l + r) / 2, r);

	return (min(left, right) + segAdd[k]);

}

int N,MM;
int LL[222222],RR[222222];

bool C(int x){
    int M=x+MM;
    if(M<N)return false;

    vint L(N),R(N);
    rep(i,N){
        L[i]=LL[i]+x;
        R[i]=RR[i]+x;
    }

    vector<pint>v;
    rep(i,N)v.pb({L[i],R[i]});
    sort(all(v));

    priority_queue<int,vint,greater<int>>que;
    int num=0;
    vint lis;
    for(int i=0;i<N;i++){
        int l,r;
        tie(l,r)=v[i];
        num++;
        que.push(r);

        if(l<num){
            int tmp=que.top();
            que.pop();
            lis.pb(tmp);
            num--;
        }
    }
    rep(i,lis.size()){
        chmax(lis[i],num+1);
    }

    vint latte(M+1);
    for(int i=0;i<M;i++)latte[i]=-1;
    for(auto r:lis)latte[r-1]++;
    for(int i=M;i>0;i--){
        if(latte[i]>0)return false;
        latte[i-1]+=latte[i];
    }
    return true;
}

signed main(){
    cin>>N>>MM;
    rep(i,N)cin>>LL[i]>>RR[i];

    int lb=-1,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}
