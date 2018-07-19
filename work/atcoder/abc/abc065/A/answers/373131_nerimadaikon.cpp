#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<sstream>
#include<list>
#include<climits>

using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define nrep(i,i0,n) for(int i=(i0);i<(int)(n);++i)
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vii;
typedef long long ll;


int main(){
int x,a,b;
cin>>x>>a>>b;
if(a>=b)cout<<"delicious"<<endl;
else if(b-a<=x)cout<<"safe"<<endl;
else cout<<"dangerous"<<endl;
	return 0;
}

