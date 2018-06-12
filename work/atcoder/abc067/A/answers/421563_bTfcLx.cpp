#include<cstdio>
#include<cstring>
#include<algorithm>
int a,b;
template<class T>
inline void read(T&a){
	char c=getchar();
	for(a=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
}
int main(){
	read(a),read(b);
	if(a%3==0||b%3==0||(a+b)%3==0)puts("Possible");
	else puts("Impossible");
	return 0;
}