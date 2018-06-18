#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <vector>
#include <queue>
#include <functional>

using std::endl;

#define ll long long int
#define FOR(a, s, n) for(int a = s; a < n; ++a)
#define LEP(a, n) for(int a = 0; a < n; ++a)
#define INF 1145141919810
#define MOD 1000000007
#define OUT std::cout
#define IN std::cin
#define itn int
#define fro for
#define sdt std
#define asn ans

struct edge
{
	ll min;
	ll max;
};

int Data[223456], tmp[223456];
int N, K, buf;

int main()
{
	IN >> N >> K;

	LEP(a, N)
	{
		IN >> buf;

		Data[buf - 1]++;

	}

	std::sort(Data, Data + N);
	std::reverse_copy(Data, Data + N, tmp);

	buf = 0;

	LEP(a, K)
	{
		buf += tmp[a];
	}

	OUT << N - buf << endl;

	return 0;
}