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
#define mp make_pair
#define x first
#define y second
pair<int,int>a[105],b[105];
int n;
bool vis[105];
int v[512][512],cp[512],u[512];
bool find(int x) {
	for (int i=1; i<=n; ++i)
		if (v[x][i] && !u[i]) {
			u[i]=1;
			if (!cp[i] || find(cp[i])) {
				cp[i]=x;
				return 1;
			}
		}
	return 0;
}

int main() {
	read(n);
	for(int i=1;i<=n;i++) {
		pair<int,int>tmp;
		read(tmp.x),read(tmp.y);
		a[i]=tmp;
	}
	for(int i=1;i<=n;i++) {
		pair<int,int>tmp;
		read(tmp.x),read(tmp.y);
		b[i]=tmp;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i].x<=b[j].x&&a[i].y<=b[j].y)
				v[i][j]=1;
	for(int i=1;i<=n;++i)
		memset(u,0,sizeof u),ans+=find(i);
	printf("%d\n",ans);
}