#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int a,b;
char mp[105][105];
int main() {
	read(a),read(b);
	for(int i=1;i<=50;i++)
		for(int j=1;j<=100;j++)
			mp[i][j]='.';
	for(int i=51;i<=100;i++)
		for(int j=1;j<=100;j++)
			mp[i][j]='#';
	b--;
	for(int i=1;i<=50&&b;i+=2)
		for(int j=1;j<=100&&b;j+=2)
			mp[i][j]='#',b--;
	a--;
	for(int i=100;i>50&&a;i-=2)
		for(int j=1;j<=100&&a;j+=2)
			mp[i][j]='.',a--;
	puts("100 100");
	for(int i=1;i<=100;i++,puts(""))
		for(int j=1;j<=100;j++)
			printf("%c",mp[i][j]);
}