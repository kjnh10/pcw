#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;

	vi vec;
	while(b)
	{
		int rem = b%10;
		vec.push_back(rem);
		b /= 10;
	}

	for(int i = sz(vec)-1; i>=0; i--)
	{
		a = a*10 + vec[i];
	}

	ll x = sqrt(a);
	if (x*x == a)
		cout << "Yes";
	else cout << "No";

	return 0;
}
