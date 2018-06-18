#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
	int A,B,push;
	cin>>A>>B;
	for(push=0;A!=B;push++){
		if(B-A>=8)
			A+=10;
		else if(B-A>=3)
			A+=5;
		else if(B-A>0)
			A++;
		else if(A-B>=8)
			A-=10;
		else if(A-B>=3)
			A-=5;
		else if(A-B>0)
			A--;
		else if(A==B)
			break;
			
	}
	cout<<push<<endl;
	return 0;
}