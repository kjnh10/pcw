// ==============================================
// Library
// ==============================================
#define _CRT_SECURE_NO_WARNINGS

// When you are using the gcc compiler, you need only the following lines.
// #include <bits/stdc++.h>

// When you are using other compilers, you need the following line instead.
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// competitive macro
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i ,n) for (int i = (n) - 1; i >= 0; i--)
#define LL long long
#define ULL unsigned long long

// const
const ULL mod = 1000000007;

// If you use this function, "cin" speeds up.
// However, you can not mix "cin" and "scanf", "cout" and "printf".
void fastIOS()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
}



// ==============================================
// ==============================================

int main()
{
	fastIOS();
	
	ULL n;
	cin >> n;

	if (n % 2 == 0)
		cout << n - 1 << "\n";
	else
		cout << n + 1 << "\n";
}