#include <iostream>
#include <string> 
using namespace std;

int main(void) {
	int	n,ans;
	char acce[101];
	bool flag = false;
	cin >> n ;
	for (int i = 0; i < n; i++)
	{
		cin >> acce[i];
	}
	if (n % 2 == 0)flag = true;
	for (int i = 0; i <= n/2; i++)
	{
		switch (acce[i])
		{
		case 'a':
			if('c' != acce[n - 1 - i])
				flag = true;
			break;
		case 'b':
			if ('b' != acce[n - 1 - i])
				flag = true;
			break;
		case 'c':
			if ('a' != acce[n - 1 - i])
				flag = true;
			break;

		default:
			break;
		}		
	}
	if (flag)ans = -1;
	else ans = n/2;


	cout << ans << endl;

	return 0;
}