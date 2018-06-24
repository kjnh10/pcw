#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <deque>
#include <bits/stdc++.h>
//#include "D:\C++\test_lib_projects\testlib.h"
using namespace std;
#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define mm(a,b) memset(a,b,sizeof(a))
#define PP puts("*********************");

// 0x3f3f3f3f3f3f3f3f
//0x3f3f3f3f

const int MAXN = 200050, SIZE = 26;
struct SAM {
	int len[MAXN], link[MAXN], next[MAXN][SIZE];
	int total, last;
	inline int newNode(int L) {
		len[++total] = L;
		link[total] = 0;
		for(int i = 0; i < SIZE; ++i) next[total][i] = 0;
		return total;
	}
	inline void Add(int c) {
		int i, p = last, cur = newNode(len[last] + 1);
		for(; p && !next[p][c]; p = link[p]) next[p][c] = cur;
		if(!p) link[cur] = 1;
		else {
			int q = next[p][c];
			if(len[q] == len[p] + 1) link[cur] = q;
			else {//>
				int clone = newNode(len[p] + 1);
				for(i = 0; i < SIZE; ++i) next[clone][i] = next[q][i];
				link[clone] = link[q];
				link[q] = link[cur] = clone;
				for(; p && next[p][c] == q; p = link[p]) next[p][c] = clone;
			}
		}
		last = cur;
	}
	void Init () {
		total = 0;
		last = newNode(0);
	}
} sam;
char str[MAXN];
int num[MAXN],idx[MAXN];
int dp[MAXN];
void solve(int k) {
	int now=1,L=0;
	while(k) {
		for(int j=0; j<SIZE; j++) {
			if(sam.next[now][j]==0)
				continue;
			int x=sam.next[now][j];
			if(k>dp[x])
				k-=dp[x];
			else {
				str[L++]='a'+j;
				now=x;
				k--;
				break;
			}
		}
	}
	str[L]='\0';
	puts(str);
}
int main() {

	int Q,k;
	scanf("%s",str);
	sam.Init();
	for(int i=0; str[i]!='\0'; i++)
		sam.Add(str[i]-'a');
	for(int i=1; i<=sam.total; i++)
		num[i]=0;
	for(int i=1; i<=sam.total; i++)
		num[sam.len[i]]++;
	for(int i=1; i<=sam.total; i++)
		num[i]+=num[i-1];
	for(int i=1; i<=sam.total; i++)
		idx[num[sam.len[i]]--]=i;

	for(int i=sam.total; i>=1; i--) {
		int now=idx[i];
		dp[now]=1;
		for(int j=0; j<SIZE; j++)
			dp[now]+=dp[sam.next[now][j]];
	}

	scanf("%d",&k);
	solve(k);

	return 0;
}