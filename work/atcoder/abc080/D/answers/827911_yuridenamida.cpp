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
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)(n) ; i++)

int imos[114514];

void solve(long long N, long long C, vector<long long> s, vector<long long> t, vector<long long> c){
	vector< pair<int,int> > seg[30];
	for(int i = 0 ; i < N ; i++){
		c[i]--;
		seg[c[i]].push_back({s[i],t[i]});
	}

	for(int i = 0 ; i < C ; i++){
		sort(seg[i].begin(),seg[i].end());
		vector< pair<int,int> > newSeg;
		if( seg[i].size() == 0 ) continue;
		pair<int,int> s = seg[i][0];
		for(int j = 1 ; j < seg[i].size() ; j++){
			if( s.second == seg[i][j].first ){
				s.second = seg[i][j].second;
			}else{
				newSeg.push_back(s);
				s = seg[i][j];
			}
		}
		newSeg.push_back(s);
		for( auto x : newSeg ){
			imos[x.first] += 1;
			imos[x.second+1] += -1;
		}
	}

	int mx = imos[0];
	for(int i = 1 ; i < 114514 ; i++)
		mx = max(mx,imos[i] = imos[i-1] + imos[i]);
	cout << mx << endl;


	
}

int main(){	
	long long C;
	long long N;
	scanf("%lld",&N);
	vector<long long> c(N-1+1);
	vector<long long> s(N-1+1);
	vector<long long> t(N-1+1);
	scanf("%lld",&C);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&s[i]);
		scanf("%lld",&t[i]);
		scanf("%lld",&c[i]);
	}
	solve(N, C, s, t, c);
	return 0;
}

