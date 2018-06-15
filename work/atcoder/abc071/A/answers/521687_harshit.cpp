#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <queue>
#include <ctime>
#include <set>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

#define pb push_back
#define mp make_pair
#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define iloop(a,b) for(ll i = a; i < b; ++i)
#define jloop(a,b) for(ll j = a; j < b; ++j)
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeofa((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define p(a) cout << a << "\n";
#define p1(a) cout << a << " ";

#define PI 3.141592653589793
#define MOD (ll)(1e9 + 7)

using namespace std;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

void solve()
{
	int x,a,b;
	cin >> x >> a >> b;
	if(abs(x-a) > abs(x-b))
		p("B")
	else
		p("A")
}
int main()
{
	bool testing = false;
	IOS
	if(testing)
	{
		freopen("test.txt","rt",stdin);
		int start = clock();
		solve();
		int end = clock();
		cout << "time: " << (end - start)/(double)(CLOCKS_PER_SEC)*1000 << " milliseconds\n";
	}
	else
	{
		solve();
	}
} 