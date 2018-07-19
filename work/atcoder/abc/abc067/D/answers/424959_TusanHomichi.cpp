#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN=1e5+5;
int N;
vvi T;

vi path;
int sz[MAXN];

bool dfs_path(int u, int p) {
        if (u == N) {
                path.push_back(N);
                return true;
        }

        for (auto v : T[u]) {
                if (v == p) continue;
                if (dfs_path(v,u)) {
                        path.push_back(u);
                        return true;
                }
        }

        return false;
}

int dfs_sz(int u, int p) {
        sz[u] = 1;
        for (auto v : T[u]) {
                if (v == p) continue;
                sz[u] += dfs_sz(v,u);
        }
        return sz[u];
}

int main() {
        cin >> N;
        T = vvi(N+1,vi());
        for (int i=0; i<N-1; i++) {
                int a,b;
                cin >> a >> b;
                T[a].push_back(b);
                T[b].push_back(a);
        }

        dfs_path(1,-1);
        dfs_sz(1,-1);

        int white = sz[path[path.size()/2-1]];
        int black = N - white;

        /*cout << "PATH: ";
        for (int i=0; i<path.size(); i++)
                cout << path[i] << " ";
        cout << "\n";

        cout << "White gets subtree: " << path[path.size()/2-1] << "\n";
        cout << "White gets " << white << " nodes\n";
        cout << "Black gets the remaining " << black << " nodes\n";*/

        if (black > white)
                cout << "Fennec\n";
        else
                cout << "Snuke\n";

}