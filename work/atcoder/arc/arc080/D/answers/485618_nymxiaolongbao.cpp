#include<iostream>
using namespace std;
int c[110][110];
int main(){
	int h,w,n,a,x=0,y=0;
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		while(a--){
			c[y][x]=i;
			if(x%2==0){
				y++;
				if(y==h)y--,x++;
			}
			else{
				y--;
				if(y==-1)y++,x++;
			}
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j)cout<<" ";
			cout<<c[i][j];
		}
		cout<<endl;
	}
	return 0;
}
