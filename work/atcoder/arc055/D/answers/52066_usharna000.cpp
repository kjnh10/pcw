#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int INF = 1<<29;
const double EPS = 1e-8;
typedef vector<int> vec;
typedef pair<int,int> P;
typedef long long ll;

int N, K;
double memo[1002][1002][2];

double dfs(int v, int k, int is_most){
    if(v == N+1 || k == K) return 0;
    if(memo[v][k][is_most] > -0.1) return memo[v][k][is_most];
    double most_big = (double)1 / (v+1);
    double eat = 0;
    if(is_most){
        eat = (double)v / N + most_big * dfs(v+1, k+1, 1) + (1-most_big) * dfs(v+1, k+1, 0);
    }
    double not_eat = most_big * dfs(v+1, k, 1) + (1-most_big) * dfs(v+1, k, 0);
    double ret = max(eat, not_eat);
    memo[v][k][is_most] = ret;
    return ret;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<=N;i++){
        for(int k=0;k<=K;k++){
            memo[i][k][0] = -1;
            memo[i][k][1] = -1;
        }
    }
    printf("%.8f\n", dfs(1, 0, 1));

    return 0;
}