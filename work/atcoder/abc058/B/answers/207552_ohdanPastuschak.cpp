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
	string e, o;
	cin >> o >> e;

	if (e.length() == o.length())
	{
		FOR(i, 0, o.length())
			cout << o[i] << e[i];
	}
	else
	{
		FOR(i, 0, o.length() - 1)
			cout << o[i] << e[i];
		cout << o[o.length() - 1];
	}




	return 0;
}