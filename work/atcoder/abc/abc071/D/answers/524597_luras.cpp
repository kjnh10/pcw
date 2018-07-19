//
//  main.cpp
//  Atcoder Beginner Contest 071 D
//
//  Created by luras on 2017/8/20.
//  Copyright © 2017年 luras. All rights reserved.
//

#define ms(x, y) memset(x, y, sizeof(x))
#define mc(x, y) memcpy(x, y, sizeof(x))
#define lson o << 1, l, mid
#define rson o << 1 | 1, mid + 1, r
#define ls o << 1
#define rs o << 1 | 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#include<list>
#include<set>
#include<string>
#include<algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")
template <class T> inline void gmax(T &a, T b){if(b > a) a = b;}
template <class T> inline void gmin(T &a, T b){if(b < a) a = b;}
using namespace std;
const int N = 100 + 10, M = 2e6 + 10, Z = 1e9 + 7, maxint = 2147483647, ms1 = 16843009, ms31 = 522133279, ms63 = 1061109567, ms127 = 2139062143;
const double PI = acos(-1.0), eps = 1e-8;
typedef long long LL;
void fre()
{
    freopen("/Users/luras/Desktop/in.txt", "r", stdin);
    freopen("/Users/luras/Desktop/out.txt", "w", stdout);
}
const int INF = 1e9;
int casenum, casei;

int n;
char s1[N], s2[N];
LL f[N];

void gadd(LL &a, LL b)
{
    a += b;
    if(a >= Z) a %= Z;
}
int main()
{
    scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    for(int i = 1; i <= n; i ++){
        if(i == 1){
            if(s1[i] == s2[i]) f[1] = 3;
            else {f[2] = 6; i ++;}
            continue;
        }
               
        if(s1[i] == s2[i] && s1[i - 1] == s2[i - 1]){
            gadd(f[i], f[i - 1] * 2);
        }
        else if(s1[i] == s2[i]){
            gadd(f[i], f[i - 1]);
        }
        else if(s1[i - 1] == s2[i - 1]){
            gadd(f[i + 1], f[i - 1] * 2);
            i ++;
        }
        else{
            gadd(f[i + 1], f[i -1] * 3);
            i ++;
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}

/*
 
 
 题意:
 
 类型:
 
 分析:
 
 优化:
 
 trick:
 
 数据:
 
 Sample Input
 
 Sample Output
 
 
 */




