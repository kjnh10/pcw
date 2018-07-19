#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char s[N];
char t[N];
int q;
int a , b , c , d;
int s1[N];
int s2[N];
int main(){
	scanf("%s" , s + 1);
	s1[0] = 0;
	for(int i = 1 ; s[i] ; ++i){
		s1[i] = s1[i - 1] + s[i] - 'A' + 1;
	}
	scanf("%s" , t + 1);
	s2[0] = 0;
	for(int i = 1 ; t[i] ; ++i){
		s2[i] = s2[i - 1] + t[i] - 'A' + 1;
	}
	scanf("%d" , &q);
	while(q--){
		scanf("%d %d %d %d" , &a , &b , &c , &d);
		if(((s1[b] - s1[a - 1]) % 3) == ((s2[d] - s2[c - 1]) % 3)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}