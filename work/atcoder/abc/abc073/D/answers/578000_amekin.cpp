#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

void shortestPath(vector<vector<int> >& dist)
{
    int n = dist.size();
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

const int INF = INT_MAX / 4;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> v(r);
    for(int i=0; i<r; ++i){
        cin >> v[i];
        -- v[i];
    }
    sort(v.begin(), v.end());

    vector<vector<int> > dist(n, vector<int>(n, INF));
    for(int i=0; i<m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        -- a;
        -- b;
        dist[a][b] = dist[b][a] = c;
    }
    shortestPath(dist);

    int ans = INF;
    do{
        int sum = 0;
        for(int i=1; i<r; ++i)
            sum += dist[v[i-1]][v[i]];
        ans = min(ans, sum);
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;

    return 0;
}
