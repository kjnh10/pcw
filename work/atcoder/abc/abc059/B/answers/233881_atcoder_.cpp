#include <bits/stdc++.h>
#include <functional>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<double,double> dd;
typedef pair<ll,ll> pll;
typedef pair<string,int> psi;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<ii> > vvip;
typedef vector<ii> vii;
typedef map<int,int> mpi;
#define pb push_back
#define F first
#define S second
//#define MOD 1000000007
#define NA -1
#define ALL(v) v.begin(),v.end()
#define mp make_pair
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define db(x) {cout << #x << " = " << (x) << endl;}
#define dba(a, x, y) {cout<<#a<<" :";FOR(i123,x,y)cout<<setw(4)<<(a)[i123];cout<<endl;}
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++) 
#define clr(x) memset(x,0,sizeof(x));
#define sz(x) int((x).size())
#define endl '\n'
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;
const ld pi = acos(-1);
#define sc(t) scanf("%d",&t)
// vector<string> split(const string &s, char delim) {
//     stringstream ss(s);
//     string item;
//     vector<string> tokens;
//     while (getline(ss, item, delim)) {
//         tokens.push_back(item);
//     }
//     return tokens;
// }

typedef pair<pll,ll> ppll;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
#define re return
#define MAX 100

 // struct compare  
 // {  
 //   bool operator()(const ii& a, const ii& b)  
 //   {  
 //       re (a.S-a.F+1 < b.S-b.F+1) || (a.S-a.F+1 == b.S-b.F+1 && a.F>b.F);
 //   }
 // };

	
int main()
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	//     freopen("output.txt","w",stdout);;
	// #endif
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	//ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	ios_base::sync_with_stdio(0); cout.precision(15); cout << fixed; cout.tie(0); cin.tie(0);
	string a,b;
	cin>>a>>b;
	if( sz(a)>sz(b))
		cout<<"GREATER"<<endl;
	else if( sz(b)>sz(a))
		cout<<"LESS"<<endl;
	else
	{
		rep(i,sz(a))
		{
			if(a[i]<b[i])
			{
				cout<<"LESS";
				re 0;
			}
			else if( a[i]>b[i])
			{
				cout<<"GREATER\n";
				re 0;
			}

		}
		cout<<"EQUAL\n";
		re 0;
	}
}