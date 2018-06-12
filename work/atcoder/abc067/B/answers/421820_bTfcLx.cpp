#include<cstdio>
#include<cstring>
#include<algorithm>
int n,k,a[60],ans;
template<class T>
inline void read(T&a){
	char c=getchar();
	for(a=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
}
int main(){
	read(n),read(k);
	for(int i=1;i<=n;i++)read(a[i]);
	std::sort(a+1,a+1+n);
	for(int i=n;i>n-k;i--)ans+=a[i];
	printf("%d\n",ans);return 0;
}