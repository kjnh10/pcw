# include <bits/stdc++.h>
# define maxn 200005
# define ll long long
# define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
# define rc(s) return cout << s,0
# define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
# define pb push_back
# define mp make_pair
//# define int ll
using namespace std;

int32_t main(){_
	//freopen("input","r",stdin);
	int l;
	int r;
	string s;
	cin >> s;
	l = r = s.size() + 1;
	for(int i = 0;i<s.size();i++)
	{
        if(s[i] == 'A') l = min(l,i);
        if(s[i] == 'Z') r = i;
	}
	rc(r - l + 1);
}
