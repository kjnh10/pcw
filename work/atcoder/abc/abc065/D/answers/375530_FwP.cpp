#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rep2(i,a,b,c) for(i=a;i<=b;i+=c)
#define maxn 100000
int par[maxn];
pair<pair<int,int>,int> ar[maxn];
pair<int,pair<int,int> > edge[2*maxn-2];

int fp(int mas){
	if(mas==par[mas]){
		return mas;
	}
	return par[mas]=fp(par[mas]);
}

bool gabung(int a,int b){
	int aa=fp(a),bb=fp(b);
	if(aa==bb){
		return false;
	}
	par[aa]=bb;
	return true;
}

int main(){
	int N,i;
	cin>>N;
	rep(i,0,N-1){
		cin>>ar[i].f.f>>ar[i].f.s;
		ar[i].s=i;
	}
	sort(ar,ar+N);
	rep(i,1,N-1){
		edge[i-1]=mp(ar[i].f.f-ar[i-1].f.f,mp(ar[i].s,ar[i-1].s));
	}
	rep(i,0,N-1){
		swap(ar[i].f.f,ar[i].f.s);
	}
	sort(ar,ar+N);
	rep(i,1,N-1){
		edge[i+N-2]=mp(ar[i].f.f-ar[i-1].f.f,mp(ar[i].s,ar[i-1].s));
	}
	rep(i,1,N-1){
		par[i]=i;
	}
	sort(edge,edge+2*N-2);
	int has=0;
	rep(i,0,2*N-2){
		if(gabung(edge[i].s.f,edge[i].s.s)){
			has+=edge[i].f;
		}
	}
	cout<<has<<"\n";
}
