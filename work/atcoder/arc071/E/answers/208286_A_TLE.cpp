#include<string>
#include<iostream>
#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
//#define scanf scanf_s
#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pub push_back
using namespace std;
typedef long long int llint;
const llint one = 1;
const llint big = (one<<30);

int main(void){
	string S,T;
	int i,Q,gen,a,b,c,d;
	vector<int> ambs={0};
	vector<int> ambt={0};
	cin>>S;
	cin>>T;
	gen=0;
	for(i=0;i<S.size();i++){
		if(S[i]=='A'){gen++;} else{gen--;}
		ambs.pub(gen);
	}gen=0;
	for(i=0;i<T.size();i++){
		if(T[i]=='A'){gen++;} else{gen--;}
		ambt.pub(gen);
	}
	scanf("%d",&Q);
	for(;Q>0;Q--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if((ambs[b]-ambs[a-1]-ambt[d]+ambt[c-1]+399999)%3==0){
			printf("YES\n");
		} else{
			printf("NO\n");
		}
	}
	return 0;
}
