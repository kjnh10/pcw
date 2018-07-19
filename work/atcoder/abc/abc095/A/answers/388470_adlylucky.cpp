#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
typedef long long ll;
ll MOD = 1e9+7;

using namespace std;

int main()
{
	string s;
	int ans=700;
	
	cin>>s;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='o')
			ans+=100;
	}
	cout<<ans<<endl;
	return 0;
}