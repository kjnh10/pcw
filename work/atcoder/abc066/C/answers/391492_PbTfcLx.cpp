#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
int n,a[200010];bool f;
std::deque<int>que;
template<class T>
inline void read(T&a){
	char c=getchar();
	for(a=0;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(!f)que.push_back(a[i]);
		else que.push_front(a[i]);
		f^=1;
	}
	if(n&1)while(!que.empty())printf("%d ",que.back()),que.pop_back();
	else while(!que.empty())printf("%d ",que.front()),que.pop_front();
	puts("");
	return 0;
}