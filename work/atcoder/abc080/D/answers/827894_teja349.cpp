//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx


using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   
vii vec1;
vector<vii > vec(100);
int main(){
    std::ios::sync_with_stdio(false);
    int n,c;
    cin>>n>>c;
    int i,s,t,ct;
    rep(i,n){
    	cin>>s>>t>>ct;
    	ct--;
    	//cout<<ct<<endl;
    	vec[ct].pb(mp(s,t));
    }
    int j;
    rep(i,c){
    	sort(vec[i].begin(),vec[i].end());
    	if(vec[i].empty())
    		continue;
    	//cout<<i<<vec[i].size()<<endl;
    	vec1.pb(mp(vec[i][0].ff,0));
    	rep(j,vec[i].size()-1){
    		if(vec[i][j].ss!=vec[i][j+1].ff){
    			vec1.pb(mp(vec[i][j].ss,1));
    			vec1.pb(mp(vec[i][j+1].ff,0));
    		}
    	}
    	vec1.pb(mp(vec[i][j].ss,1));
    }
    //cout<<vec1.size()<<endl;
    int ans=0,maxi=0;
    sort(vec1.begin(),vec1.end());
    rep(i,vec1.size()){
    	//cout<<vec1[i].ff<<" "<<vec1[i].ss<<endl;
    	if(vec1[i].ss){
    		ans--;
    	}
    	else{
    		ans++;
    	}
    	maxi=max(ans,maxi);
    }
    cout<<maxi<<endl;
    return 0;  
    
}

