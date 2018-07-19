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
using namespace std;

// Union-Find木
class UnionFindTree
{
private:
    const int n;
    int groupNum;       // グループの数
    vector<int> parent; // 親ノード
    vector<int> rank;   // 木の高さの上限
    vector<int> num;    // グループの要素数
    int find(int i){
        if(parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
public:
    UnionFindTree(int n) : n(n){ // コンストラクタ
        groupNum = n;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
        rank.assign(n, 0);
        num.assign(n, 1);
    }
    void unite(int a, int b){ // aとbのグループを併合
        if((a = find(a)) != (b = find(b))){
            if(rank[a] < rank[b]){
                parent[a] = b;
                num[b] += num[a];
            }
            else{
                parent[b] = a;
                if(rank[a] == rank[b])
                    ++ rank[a];
                num[a] += num[b];
            }
            -- groupNum;
        }
    }
    bool same(int a, int b){ // aとbのグループが同じかを調べる
        return find(a) == find(b);
    }
    int getNum(){ // グループの数を返す
        return groupNum;
    }
    int getNum(int a){ // aのグループの要素数を返す
        return num[find(a)];
    }
    void getGroup(vector<vector<int> >& group){ // グループ構成を返す
        map<int, int> index;
        group.clear();
        for(int i=0; i<n; ++i){
            int a = find(i);
            if(index.find(a) == index.end()){
                index[a] = group.size();
                group.resize(group.size() + 1);
            }
            group[index[a]].push_back(i);
        }
    }
};

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int> > edges(n+1);
    for(int i=0; i<m; ++i){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    UnionFindTree uft(n+1);
    vector<bool> ans(n+1, false);
    for(int a=n; a>=1; --a){
        for(int b : edges[a]){
            if(a < b)
                uft.unite(a, b);
        }

        if(uft.same(s, a))
            ans[a] = true;
    }

    for(int i=1; i<=n; ++i){
        if(ans[i])
            cout << i << endl;
    }

    return 0;
}