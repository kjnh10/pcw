    #include<iostream>
    #include<algorithm>
    #include<vector>
    #include<queue>
    #include<map>
    #include<set>
    #include<string>
    #include<stack>
    #include<cstdio>
    #include<cmath>
    using namespace std;
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<int,int> P;
    typedef pair<int,P> P1;
     
    #define fr first
    #define sc second
    #define mp make_pair
    #define pb push_back
    #define rep(i,x) for(int i=0;i<x;i++)
    #define rep1(i,x) for(int i=1;i<=x;i++)
    #define rrep(i,x) for(int i=x-1;i>=0;i--)
    #define rrep1(i,x) for(int i=x;i>0;i--)
    #define sor(v) sort(v.begin(),v.end())
    #define rev(s) reverse(s.begin(),s.end())
    #define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
    #define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
    #define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
    #define mp1(a,b,c) P1(a,P(b,c))
     
    const int INF=1000000000;
    const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
     
    int main(){
    	int n,k;
    	ld w[1002],p[1002];
    	
    	cin >> n >> k;
    	rep(i,n){
    		cin >> w[i] >> p[i];
    		p[i] /= 100.0;
    	}
    	
    	ld l = 0.0 , r = 1.0;
    	while(l+0.000000001 < r){
    		ld m = (l+r)/2;
    		vector<ld> vec;
    		rep(i,n){
    			vec.pb(w[i]*p[i]-w[i]*m);
    		}
    		sor(vec);
    		rev(vec);
    		ld ret = 0;
    		rep(i,k)ret += vec[i];
    		if(ret < 0.0)r = m;
    		else l = m;
    	}
    	cout.precision(20);
    	cout << l*100 << endl;
    }