#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
ll m1 = 1000000007, m2 = 998244353;
ll t1 = 555522277, t2 = 895612782;
ll p1[505050], p2[505050];
ll ip1[505050], ip2[505050];
typedef pair<ll, ll>pii;
ll po(ll a, ll b, ll m)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2, m);
	z = z*z%m;
	if (b & 1)z = z*a%m;
	return z;
}
ll inv(ll a, ll m)
{
	return po(a, m - 2, m);
}
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	p1[0] = p2[0] = ip1[0] = ip2[0] = 1;
	for (int i = 0; i < 505000; i++)p1[i + 1] = p1[i] * t1%m1, p2[i + 1] = p2[i] * t2%m2;
	ll it1 = inv(t1, m1), it2 = inv(t2, m2);
	for (int i = 0; i < 505000; i++)ip1[i + 1] = ip1[i] * it1%m1, ip2[i + 1] = ip2[i] * it2%m2;
	ll n1 = 0, n2 = 0;
	vector<pii>v;
	vector<int>pl;
	v.push_back(make_pair(0, 0));
	pl.push_back(num + 10);
	int now = num + 10;
	for (int i = 0; i < num; i++)
	{
		if (s[i] == '+')n1 = (n1 + p1[now]) % m1, n2 = (n2 + p2[now]) % m2;
		else if (s[i] == '-')n1 = (n1 + m1 - p1[now]) % m1, n2 = (n2 + m2 - p2[now]) % m2;
		else if (s[i] == '>')now++;
		else now--;
		v.push_back(make_pair(n1, n2)), pl.push_back(now);
	}
	ll ans = 0;
	map<pii, int>ma;
	for (int i = num; i >= 0; i--)
	{
		int dif = pl[i] - (num + 10);
		ll mk1, mk2;
		if (dif >= 0)mk1 = (v[i].first + n1*p1[dif]) % m1, mk2 = (v[i].second + n2*p2[dif]) % m2;
		else mk1 = (v[i].first + n1*ip1[-dif]) % m1, mk2 = (v[i].second + n2*ip2[-dif]) % m2;
		ans += ma[make_pair(mk1, mk2)];
		ma[v[i]]++;
	}
	printf("%lld\n", ans);
}