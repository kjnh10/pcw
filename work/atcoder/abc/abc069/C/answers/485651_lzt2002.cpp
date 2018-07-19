#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

const int inf=2147483647;

int n1,n2,n4;

int n;

int main()
{
	cin>>n;
	
	int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		
		if(x%2!=0) n1++;
		else if(x%4!=0) n2++;
		else n4++;
	}
	
	if(n1>n4+1)
	{
		puts("No");
		return 0;
	}
	
	if(n1==n4+1)
	{
		if(n2==0)
		{
			puts("Yes");
			return 0;
		}
		else
		{
			puts("No");
			return 0;
		}
	}
	
	puts("Yes");
	return 0;
}
