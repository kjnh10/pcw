#include <iostream>

using namespace std;

int main()
{
	int s1, s2, s3;
	int e1, e2, e3;
	int total;

	cin >> s1 >> e1;
	cin >> s2 >> e2;
	cin >> s3 >> e3;

	total = (s1 / 10) * e1 + (s2 / 10) * e2 + (s3 / 10) * e3;
	cout << total << endl;

	return (0);
}