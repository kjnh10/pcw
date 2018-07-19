#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

string a,b;
char c;
int ans;

int main(){
    cin >> a >> b;
    ans = stoi(a) - stoi(b);
    c = a[0];a[0] = '9';
    ans = max(ans,stoi(a) - stoi(b));
    a[0] = c;
    c = a[1];a[1] = '9';
    ans = max(ans,stoi(a) - stoi(b));
    a[1] = c;
    c = a[2];a[2] = '9';
    ans = max(ans,stoi(a) - stoi(b));
    a[2] = c;
    c = b[0];b[0] = '1';
    ans = max(ans,stoi(a) - stoi(b));
    b[0] = c;
    c = b[1];b[1] = '0';
    ans = max(ans,stoi(a) - stoi(b));
    b[1] = c;
    c = b[2];b[2] = '0';
    ans = max(ans,stoi(a) - stoi(b));
    b[2] = c;
    cout << ans << endl;
	return 0;
}
