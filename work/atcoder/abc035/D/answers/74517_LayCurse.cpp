#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)

#define ll long long
#define ull unsigned ll

void reader(int *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(ll *x){int k,m=0;*x=0;for(;;){mygc(k);if(k=='-'){m=1;break;}if('0'<=k&&k<='9'){*x=k-'0';break;}}for(;;){mygc(k);if(k<'0'||k>'9')break;*x=(*x)*10+k-'0';}if(m)(*x)=-(*x);}
void reader(double *x){scanf("%lf",x);}
int reader(char c[]){int i,s=0;for(;;){mygc(i);if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF) break;}c[s++]=i;for(;;){mygc(i);if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF) break;c[s++]=i;}c[s]='\0';return s;}
template <class T, class S> void reader(T *x, S *y){reader(x);reader(y);}
template <class T, class S, class U> void reader(T *x, S *y, U *z){reader(x);reader(y);reader(z);}
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){reader(x);reader(y);reader(z);reader(w);}

void writer(int x, char c){int s=0,m=0;char f[10];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(ll x, char c){int s=0,m=0;char f[20];if(x<0)m=1,x=-x;while(x)f[s++]=x%10,x/=10;if(!s)f[s++]=0;if(m)mypc('-');while(s--)mypc(f[s]+'0');mypc(c);}
void writer(double x, char c){printf("%.15f",x);mypc(c);}
void writer(const char c[]){int i;for(i=0;c[i]!='\0';i++)mypc(c[i]);}
void writer(const char x[], char c){int i;for(i=0;x[i]!='\0';i++)mypc(x[i]);mypc(c);}
template<class T> void writerLn(T x){writer(x,'\n');}
template<class T, class S> void writerLn(T x, S y){writer(x,' ');writer(y,'\n');}
template<class T, class S, class U> void writerLn(T x, S y, U z){writer(x,' ');writer(y,' ');writer(z,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){mypc('\n');return;}rep(i,n-1)writer(x[i],' ');writer(x[n-1],'\n');}

char memarr[77000000]; void *mem = memarr;
#define MD 1000000007

template <class T>
struct DijkstraHeap {
  int *hp, *place, size; char *visited; T *val;

  void malloc(int N){hp=(int*)std::malloc(N*sizeof(int));place=(int*)std::malloc(N*sizeof(int));visited=(char*)std::malloc(N*sizeof(char));val=(T*)std::malloc(N*sizeof(T));}
  void free(){free(hp);free(place);free(visited);free(val);}
  void* malloc(int N, void *workMemory){hp=(int*)workMemory;place=(int*)(hp+N);visited=(char*)(place+N);val=(T*)(visited+N);workMemory=(void*)(val+N);return workMemory;}
  void init(int N){int i;size=0;rep(i,N)place[i]=-1,visited[i]=0;}
  void up(int n){int m;while(n){m=(n-1)/2;if(val[hp[m]]<=val[hp[n]])break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void down(int n){int m;for(;;){m=2*n+1;if(m>=size)break;if(m+1<size&&val[hp[m]]>val[hp[m+1]])m++;if(val[hp[m]]>=val[hp[n]]) break;swap(hp[m],hp[n]);swap(place[hp[m]],place[hp[n]]);n=m;}}
  void change(int n, T v){if(visited[n]||(place[n]>=0&&val[n]<=v))return;val[n]=v;if(place[n]==-1)place[n]=size,hp[size++]=n,up(place[n]);else up(place[n]);}
  int pop(void){int res=hp[0];place[res]=-1;size--;if(size)hp[0]=hp[size],place[hp[0]]=0,down(0);visited[res]=1;return res;}
};

template<class T> void* setDirectEdge(int N, int M, int A[], int B[], T C[], int **es, int ***edge, T ***cost, void *workMemory){int i;*es=(int*)workMemory;*edge=(int**)((*es)+N);(*edge)[0]=(int*)((*edge)+N);rep(i,N)(*es)[i]=0;rep(i,M)(*es)[A[i]]++;REP(i,1,N)(*edge)[i]=(*edge)[i-1]+(*es)[i-1];(*cost)=(T**)((*edge)[N-1]+(*es)[N-1]);(*cost)[0]=(T*)((*cost)+N);REP(i,1,N)(*cost)[i] = (*cost)[i-1]+(*es)[i-1];workMemory= (void*)((*cost)[N-1]+(*es)[N-1]);rep(i,N)(*es)[i] = 0;rep(i,M)(*edge)[A[i]][(*es)[A[i]]]=B[i],(*cost)[A[i]][(*es)[A[i]]++]=C[i];return workMemory;}
template<class T1, class T2> void getDist(int N, int root, int *es, int **edge, T1 **cost, T2 dist[], void *mem){int i,j;DijkstraHeap<T2> hp;hp.malloc(N,mem);hp.init(N);hp.change(root,0);while(hp.size){i=hp.pop();rep(j,es[i])hp.change(edge[i][j],hp.val[i]+cost[i][j]);}rep(i,N)dist[i]=hp.visited[i]?hp.val[i]:-1;}

int N, M, T;
int G[200000];
int A[200000], B[200000]; ll C[200000];

int *es, **edge;
ll **cost;

ll dist[200000], dist2[200000];

int main(){
  int i, j, k;
  ll res = 0, t;

  reader(&N,&M,&T);
  rep(i,N) reader(G+i);
  rep(i,M) reader(A+i,B+i,C+i), A[i]--, B[i]--;

  mem = setDirectEdge(N, M, A, B, C, &es, &edge, &cost, mem);
  getDist(N, 0, es, edge, cost, dist, mem);

  mem = setDirectEdge(N, M, B, A, C, &es, &edge, &cost, mem);
  getDist(N, 0, es, edge, cost, dist2, mem);

  rep(i,N){
    if(dist[i] < 0 || dist2[i] < 0) continue;
    t = T - dist[i] - dist2[i];
    if(t < 0) continue;
    res = max(res, t * G[i]);
  }
  writerLn(res);

  return 0;
}
