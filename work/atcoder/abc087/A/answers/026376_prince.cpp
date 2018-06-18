#ifdef _WIN32
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

// 継承可能な型
template <class Type>
struct IN : Type
{
	IN()
	{
		std::cin >> *this;
	}
};

// 継承不可能な型
template <class Type>
struct IN_
{
	Type val;

	IN_()
	{
		std::cin >> val;
	}

	operator Type&()
	{
		return val;
	}

	IN_<Type>& operator=(const Type& _value)
	{
		val = _value;
		return *this;
	}
};

template <class Char, class Type>
std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const IN_<Type>& value)
{
	return os << value.val;
}

template <class Char, class Type>
std::basic_istream<Char>& operator >>(std::basic_istream<Char>& is, IN_<Type>& value)
{
	return is >> value.val;
}

template <class Type>
void OUT(const Type& value)
{
	std::cout << value << std::endl;
}

template <class Type, class ... Args>
void OUT(const Type& value, const Args& ... args)
{
	std::cout << value << ' ';
	OUT(args...);
}

using ll = long long;
using inll = IN_<ll>;
using vll = std::vector<ll>;
using setll = std::set<ll>;
using msetll = std::multiset<ll>;
using instr = IN<std::string>;

#define FOR(i, m, n) for (ll (i) = (m); (i) < (n); ++(i))
#define REP(i, n) for (ll (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for (ll (i) = (n); (i) >= 0; --(i))
#define ITRREP(it, v) for (auto (it) = (v).begin(); (it) != (v).end(); ++(it))
#define ITRREPR(it, v) for (auto (it) = (v).rbegin(); (it) != (v).rend(); ++(it))
#define DIVUP(a, b) (((a) + (b) - 1) / (b))

void Main();

int main()
{
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	Main();

#ifdef _DEBUG
	system("pause");
#endif

	return 0;
}

using namespace std;

//////////////////////////////

void Main()
{
	inll x, a, b;

	return OUT((x - a) % b);
}
