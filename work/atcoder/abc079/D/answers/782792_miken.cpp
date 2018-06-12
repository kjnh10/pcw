                                #include <bits/stdc++.h>
                                #include<iostream>
                                #include<cstdio>
                                #include<vector>
                                #include<queue>
                                #include<map>
                                #include<cstring>
                                #include<string>
                                #include <math.h>
                                #include<algorithm>
                            //    #include <boost/multiprecision/cpp_int.hpp>
                                #include<functional>
                       #define int long long
                                #define inf  10000000000007
                                #define pa pair<int,int>
                                #define ll long long
                                #define pal pair<double,pa>
                                #define ppa pair<pa,int>
                                #define ppap pair<int,pa>
                                #define ssa pair<string,int>
                                #define  mp make_pair
                                #define  pb push_back
                                #define EPS (1e-10)
                                #define equals(a,b) (fabs((a)-(b))<EPS)
                         
                                using namespace std;
                      
                                class Point{
                                	public:
                                	double x,y;
                                	Point(double x=0,double y=0):x(x),y(y) {}
                                	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
                                	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
                                	Point operator * (double a) {return Point(x*a,y*a);}
                                	Point operator / (double a) {return Point(x/a,y/a);}
                                	double absv() {return sqrt(norm());}
                                	double norm() {return x*x+y*y;}
                                	bool operator < (const Point &p) const{
                                		return x != p.x ? x<p.x: y<p.y;
                                	}
                                	bool operator == (const Point &p) const{
                                		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
                                	}
                                };
                                typedef Point Vector;
                         
                                struct Segment{
                                Point p1,p2;
                                };
                                 double dot(Vector a,Vector b){
                                	return a.x*b.x+a.y*b.y;
                                }
                                double cross(Vector a,Vector b){
                                	return a.x*b.y-a.y*b.x;
                                }
                            
    bool parareru(Point a,Point b,Point c,Point d){
    //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
    	return abs(cross(a-b,d-c))<EPS;
    }
    double distance_ls_p(Point a, Point b, Point c) {
      if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
      if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
      return abs(cross(b-a, c-a)) / (b-a).absv();
    }
    bool is_intersected_ls(Segment a,Segment b) {
    	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return false;
    	if(parareru((a.p2),(a.p1),(a.p1),(b.p2))&&parareru((a.p2),(a.p1),(a.p1),(b.p1))){
    //		cout<<"sss"<<endl;
    		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
    		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
    		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
    		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
    		return false;
    	}
      else return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
    }
     
    double segment_dis(Segment a,Segment b){
    	if(is_intersected_ls(a,b))return 0;
    	double r=distance_ls_p(a.p1, a.p2, b.p1);
    	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
    	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
    	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
    	return r;
    }
    Point intersection_ls(Segment a, Segment b) {
      Point ba = b.p2-b.p1;
      double d1 = abs(cross(ba, a.p1-b.p1));
      double d2 = abs(cross(ba, a.p2-b.p1));
      double t = d1 / (d1 + d2);
     
      return a.p1 + (a.p2-a.p1) * t;
    }
     
                    string itos( int i ) {
                    ostringstream s ;
                    s << i ;
                    return s.str() ;
                    }
                     
                    int gcd(int v,int b){
                    	if(v>b) return gcd(b,v);
                    	if(v==b) return b;
                    	if(b%v==0) return v;
                    	return gcd(v,b%v);
                    }
     
                    double distans(double x1,double y1,double x2,double y2){
                    	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                    	return sqrt(rr);
                    	
                    }
                    /*
    int pr[100010];
    //int inv[100010];
    */ 
    int beki(int wa,int rr,int warukazu){
    	if(rr==0) return 1ll;
    	if(rr==1) return wa%warukazu;
    	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;
    	int zx=beki(wa,rr/2,warukazu);
    	return (zx*zx)%warukazu;
    }
      /*
    void gya(){
    	pr[0]=1;
    	for(int i=1;i<100010;i++){
    		pr[i]=(pr[i-1]*i)%inf;
    	}
    	for(int i=0;i<100010;i++) inv[i]=beki(pr[i],inf-2);
    	
    }
     
    */
     //sort(ve.begin(),ve.end(),greater<int>());
                             //----------------kokomade tenpure------------
    //vector<double> ans(100000000),ans2(100000000);
    /*
    int par[200100],ranks[200100],kosuu[200100];     
     
    void shoki(int n){
    	for(int i=0;i<n;i++){
    		par[i]=i;
    		ranks[i]=0;
    		kosuu[i]=1;
    	}
    }
     
    int root(int x){
    	return par[x]==x ? x : par[x]=root(par[x]);
    }
     
    bool same(int x,int y){
    return root(x)==root(y);
    }
     
    void unite(int x,int y){
     x=root(x);
     y=root(y);
    	int xx=kosuu[x],yy=kosuu[y];
     if(x==y) return;
    	if(ranks[x]<ranks[y]){
    		par[x]=y;
    		kosuu[y]=yy+xx;
    	}
     else {
    	par[y]=x;
    	if(ranks[x]==ranks[y]) ranks[x]=ranks[x]+1;
     	kosuu[x]=yy+xx;
     }
    	return;
    }
    */



signed main(){
	int n,m;
int a[10][10];
	cin>>n>>m;
	
	for(int i=0;i<=9;i++) for(int j=0;j<=9;j++) cin>>a[i][j];
	
	for(int k=0;k<=9;k++)for(int i=0;i<=9;i++) for(int j=0;j<=9;j++){
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	}
int ans=0;	
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		int t;
		cin>>t;
	//	cout<<t<<endl;
		if(t==-1) continue;
		ans+=a[t][1];
	//	cout<<a[t][1]<<endl;
	}
	cout<<ans<<endl;
}
