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
};

class Edge
{
public:
	int a, b, y;
	bool operator<(const Edge& e) const{
		return y < e.y;
	}
};

class Query
{
public:
	int v, w, index;
	bool operator<(const Query& q) const{
		return w < q.w;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Edge> edges(m);
	for(int i=0; i<m; ++i)
		cin >> edges[i].a >> edges[i].b >> edges[i].y;
	sort(edges.rbegin(), edges.rend());

	int q;
	cin >> q;
	vector<Query> query(q);
	for(int i=0; i<q; ++i){
		cin >> query[i].v >> query[i].w;
		query[i].index = i;
	}
	sort(query.rbegin(), query.rend());

	int k = 0;
	UnionFindTree uft(n+1);
	vector<int> ans(q);
	for(int i=0; i<q; ++i){
		while(k < m && query[i].w < edges[k].y){
			uft.unite(edges[k].a, edges[k].b);
			++ k;
		}
		ans[query[i].index] = uft.getNum(query[i].v);
	}

	for(int i=0; i<q; ++i)
		cout << ans[i] << endl;

	return 0;
}