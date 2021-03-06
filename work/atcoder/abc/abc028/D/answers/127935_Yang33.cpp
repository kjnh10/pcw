#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  xtimex  Problem: ABC028 D / Link: http://abc028.contest.atcoder.jp/tasks/abc028_d ----- */
/* ------問題------

2 つの整数 N、K が与えられます。
1 以上 N 以下の整数のなかからどれか 1 つ、等確率に選ぶ機械を考えます。
その機械を 3 回動かした時、選ばれた 3 つの数の中央値が K となる確率を求めてください。

-----問題ここまで----- */
/* -----解説等-----

場合分けをしたら終わってしまった。
３つとも違う値、2つはＫのとき、３つともＫのときを足し合わせたものが総組み合わせ。

 ----解説ここまで---- */

double N, K;

double temp = 0, ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    temp += 6 * (K - 1)*(N - K);
    temp += 3 * (K - 1) + 3 * (N - K);
    temp += 1;


    ans = temp / (N*N*N);
    printf("%.12f\n", ans);

    return 0;
}