
#include<cstdio>
#include <iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<functional>
#include<cmath>
#include<map>
#include<set>

using namespace std;

int main()
{
	set<int> q;
	int a[5];
	for (int i = 0; i < 5; i++)cin >> a[i];

	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 5; j++) {
			for (int k = i + 1; k < 5; k++) {
				int sum = 0;
				if (j != k) {
					sum = a[i] + a[j] + a[k];
					q.insert(sum);
				}
			}
		}
	}
	auto it = q.begin();
	int i = 0;
	while (it != q.end()) {
		i++;
		if (i == q.size() - 2)
			cout << *it << endl;
		++it;
	}
	return 0;
}