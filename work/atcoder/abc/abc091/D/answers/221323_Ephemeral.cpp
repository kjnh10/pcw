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
int a[200005],b[200005],c[200005],d[200005],n,ans;
int main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		read(b[i]);
	for(int i=0;i<=29;i++) {
		int s1=0,s2=0,sum=0;
		for(int j=1;j<=n;j++)
			s1^=(a[j]>>i)&1,s2^=(b[j]>>i)&1;
		sum=(s1+s2)*n%2;
		if(i==0) {
			ans+=sum;
			continue;
		}
		for(int j=1;j<=n;j++)
			c[j]=a[j]&((1<<i)-1);
		for(int j=1;j<=n;j++)
			d[j]=b[j]&((1<<i)-1);
		sort(c+1,c+n+1);
		sort(d+1,d+n+1);
		int r=n;
		for(int j=1;j<=n;j++) {
			while(d[r]+c[j]>=(1<<i))
				r--;
			sum^=(n-r)&1;
		}
		ans+=sum<<i;
	}
	printf("%d",ans);
}
