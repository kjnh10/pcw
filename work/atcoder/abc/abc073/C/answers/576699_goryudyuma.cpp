#include <iostream>
#include<set>

using namespace std;

int main()
{
	long long int N;
	cin >> N;
	set<long long int>S;
	for (size_t i = 0; i < N; i++)
	{
		long long int A;
		cin >> A;
		if (S.count(A))
		{
			S.erase(A);
		}
		else {
			S.insert(A);
		}
	}
	cout << S.size() << endl;
	return 0;
}

