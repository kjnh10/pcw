/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . ___
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         ·ð×æ±£ÓÓ       ÓÀÎÞBUG
*/
//use readint!
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma GCC optimize(5)
#pragma GCC optimize(6)
#pragma GCC optimize(7)
#pragma GCC optimize(8)
#pragma GCC optimize(9)
#include<map>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<set>
#include<cmath>
#include<stdio.h>
#include<fstream>
#include<assert.h>
#include<time.h>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<string.h>
#define mp make_pair
#define ll long long
#define all(v) v.begin(),v.end()
#define memset(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=1e9;
inline int pt(int a[],int l,int r){
	int p,i,j;
	p=a[l];
	i=l;
	j=r+1;
	for(;;){
		while(a[++i]<p) if(i>=r) break;
		while(a[--j]>p) if(j<=l) break;
		if(i>=j) break;
		else swap(a[i],a[j]);
	}
	if(j==l) return j;
	swap(a[l],a[j]);
	return j;
}
inline void q_sort(int a[],int l,int r){
	int q;
	if(r>l){
		q=pt(a,l,r);
		q_sort(a,l,q-1);
		q_sort(a,q+1,r);
	}
}
inline int readint(){
    int x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int ans=123456789;
int W[300005],E[300005];
int main(){
	int i,j,n;
	string s;
	cin>>n>>s;
	s=' '+s;
	for(i=1;i<=n;i++){
		E[i]=E[i-1]+(s[i]=='E');
	}
	for(i=n;i>=1;i--) W[i]=W[i+1]+(s[i]=='W');
	for(i=1;i<=n;i++){
		ans=min(ans,n-1-E[i-1]-W[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}