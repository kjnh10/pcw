#include<iostream>
using namespace std;
int main(){
	int x,a,b;
	cin>>x>>a>>b;
	int c=b-a;
	if(c<=0){
		cout<<"delicious"<<endl;
	}else if(c<=x){
		cout<<"safe"<<endl;
	}else{
		cout<<"dangerous"<<endl;
	}
	return 0;
}