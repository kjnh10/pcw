#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	#ifndef ONLINE_JUDGE
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	#endif
	int a,b,c;
	set<int> s;
	cin>>a>>b>>c;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	cout<<s.size()<<'\n';
	return 0;
}	