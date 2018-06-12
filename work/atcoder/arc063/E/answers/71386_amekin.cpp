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

const int INVALID = INT_MAX / 2;

vector<vector<int> > edges;
vector<pair<int, int> > node;

bool solve(int curr, int prev)
{
    if(node[curr].first == INVALID){
        node[curr].first = node[prev].first - 1;
        node[curr].second = node[prev].second + 1;
    }

    for(int next : edges[curr]){
        if(next == prev)
            continue;

        if(!solve(next, curr))
            return false;
        if(!((node[curr].first % 2) ^ (node[next].first % 2)))
            return false;

        node[curr].first = max(node[curr].first, node[next].first - 1);
        node[curr].second = min(node[curr].second, node[next].second + 1);
        if(node[curr].second < node[curr].first)
            return false;
    }

    return true;
}

bool solve2(int curr, int prev)
{
    if(prev != -1){
        if(node[curr].first <= node[prev].first - 1 && node[prev].first - 1 <= node[curr].second)
            node[curr].first = node[prev].first - 1;
        else if(node[curr].first <= node[prev].first + 1 && node[prev].first + 1 <= node[curr].second)
            node[curr].first = node[prev].first + 1;
        else
            return false;
    }

    for(int next : edges[curr]){
        if(next == prev)
            continue;
        if(!solve2(next, curr))
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    edges.assign(n, vector<int>());
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        -- a;
        -- b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int k;
    cin >> k;
    node.assign(n, make_pair(INVALID, INVALID));
    int curr;
    for(int i=0; i<k; ++i){
        int v, p;
        cin >> v >> p;
        -- v;
        node[v] = make_pair(p, p);
        curr = v;
    }

    if(!solve(curr, -1)){
        cout << "No" << endl;
    }
    else if(!solve2(curr, -1)){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        for(int i=0; i<n; ++i)
            cout << node[i].first << endl;
    }

    return 0;
}