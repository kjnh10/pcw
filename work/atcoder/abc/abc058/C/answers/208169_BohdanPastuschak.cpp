#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <fstream>
#include <map>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e9+1
#define pdd pair<double,double>
#define pll pair<ll, ll>
#define pii pair<int,int>
#define MP make_pair
#define vi vector<ll>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

int main()
{
	int n; cin >> n;
	vector<string> s(n);
	FOR(i, 0, n)
		cin >> s[i];

	vector<map<char, int>> m(n);
	FOR(i, 0, n)
	{
		FOR(j, 0, s[i].length())
			m[i][s[i][j]]++;
	}

	map<char, int> acc;
	FOR(i, 'a', 'z' + 1)
	{
		acc[i] = m[0][i];
		FOR(j, 1, n)
			acc[i] = min(acc[i], m[j][i]);
	}


	FOR(i, 'a', 'z' + 1)
	{
		FOR(j, 0, acc[i])
			cout << (char)i;
	}
	

	return 0;
}