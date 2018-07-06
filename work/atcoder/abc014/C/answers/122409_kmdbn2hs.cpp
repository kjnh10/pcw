#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class ABC014C
{
public:
	void abc014c(int n, vector< pair<int, int> > q)
	{
		vector<int> c(pow(10,6)+5, 0);

		int ans=0;

		for(int i=0; i<q.size(); i++)
		{
			c[q[i].first] += 1;
			c[q[i].second+1] -= 1;
		}

		for(int i=0; i<pow(10, 6); i++)
			c[i+1] += c[i];

		for(int i=0; i<pow(10, 6)+1; i++)
			ans = max(ans, c[i]);

		cout << ans << endl;
	}
};


int main(void)
{
	vector< pair<int, int> > q;

	int n;
	int a,b;

	ABC014C abc;

	cin >> n;

	for(int i=0; i<n; i++)
	{
		cin >> a >> b;
		q.push_back(pair<int, int>(a, b));
	}

	abc.abc014c(n, q);

	return 0;
}
