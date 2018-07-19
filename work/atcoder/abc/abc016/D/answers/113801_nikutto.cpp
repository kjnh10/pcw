#include<bits/stdc++.h>
using namespace std;

typedef complex<double> P;
const double EPS=1e-9;

double cross(P lhs,P rhs){
	return lhs.real()*rhs.imag()-lhs.imag()*rhs.real();
}

double dot(P lhs,P rhs){return lhs.real()*rhs.real()+lhs.imag()*rhs.imag();}
int ccw(P a,P b,P c){
	b-=a;c-=a;
	if(cross(b,c)>EPS) return 1;//clockwise
	if(cross(b,c)<-EPS) return -1;//un
	if(dot(b,c)<-EPS) return 2;
	if(abs(b)>abs(c)) return -2;
	return 0;
}

bool is_cross(P p1,P p2,P a,P b){
	return ccw(p1,p2,a)*ccw(p1,p2,b)<=0 && ccw(a,b,p1)*ccw(a,b,p2)<=0;
	
}

int main(){
	double x,y;
	cin>>x>>y;
	P a=P(x,y);
	cin>>x>>y;
	P b=P(x,y);
	int n;
	cin>>n;
	vector<P> xy(n);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		xy[i]=P(x,y);
	}
	int res=0;
	for(int i=0;i<n;i++){
		res+=is_cross(xy[i],xy[(i+1)%n],a,b);
	
	}
	res/=2;
	res++;
	cout<<res<<endl;
	return 0;
}
