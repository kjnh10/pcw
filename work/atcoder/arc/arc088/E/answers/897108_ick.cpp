#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200005
 
int n;
int c[maxn];
int cnt[30],fuck[30],nxt[maxn],fir[maxn],p[30];
char s[maxn],t[maxn];
long long ans;
 
inline int read(){
    int x=0,f=1; char ch=getchar();
    for (;ch<'0'||ch>'9';ch=getchar()) if (ch=='-') f=-1;
    for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
 
void clear(){
    memset(cnt,0,sizeof(cnt)),memset(fuck,0,sizeof(fuck));
    memset(fir,0,sizeof(fir)),memset(c,0,sizeof(c));
}
 
void change(int i,int v){for (;i<=n;i+=i&(-i)) c[i]+=v;}
int query(int i){int ret=0; for (;i;i-=i&(-i)) ret+=c[i]; return ret;}
 
int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
    int pps=0,fuckpps=0;
    for (int i=0;i<26;i++) if (cnt[i]&1) pps++,fuckpps=i;
    if (!(n&1)&&pps){puts("-1"); return 0;}
    if ((n&1)&&pps!=1){puts("-1"); return 0;}
    int top=0;
    for (int i=1;i<=n;i++)
        if (++fuck[s[i]-'a']<=(cnt[s[i]-'a']>>1)) t[++top]=s[i];
    if (n&1) t[++top]=fuckpps+'a';
    for (int i=(n>>1);i;i--) t[++top]=t[i];
    for (int i=n;i;i--) nxt[i]=fir[t[i]-'a'],fir[t[i]-'a']=i;
    for (int i=0;i<26;i++) p[i]=fir[i];
    ans=0;
    for (int i=1;i<=n;i++){
        ans+=i-1-query(p[s[i]-'a']),change(p[s[i]-'a'],1);
        p[s[i]-'a']=nxt[p[s[i]-'a']];
    }
    printf("%lld\n",ans);
    return 0;
}