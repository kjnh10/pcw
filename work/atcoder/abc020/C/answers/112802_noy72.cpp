#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 1000000000;
using namespace std;


const int N = 11;

struct point{ int x, y; };
int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};

int h, w, t;
char M[N][N];
point s, g;

bool bfs(int mid){
    int dis[N][N];
    bool used[N][N];
    queue<point> q;
    rep(i,N) rep(j,N) dis[i][j] = INF;

    dis[s.y][s.x] = 0;
    q.push(s);

    point u;
    int cost;
    while(!q.empty()){
    //show(mid); rep(i,h){ rep(j,w){ cout << dis[i][j] << ' '; } cout << endl; } cout << endl;

        u = q.front(); q.pop();
        rep(i,4){
            point next;
            int cost;
            next.x = u.x + dx[i];
            next.y = u.y + dy[i];
            if(M[next.y][next.x] == '.') cost = dis[u.y][u.x] + 1;
            else if(M[next.y][next.x] == '#') cost = dis[u.y][u.x] + mid;
            else cost = dis[u.y][u.x];

            if(next.x < 0 || next.x >= w || next.y < 0 || next.y >= h) continue;
            if(dis[next.y][next.x] > cost){
                dis[next.y][next.x] = cost;
                q.push(next);
            }
        }
    }
    //show(dis[g.y][g.x])
    return (dis[g.y][g.x] < t);
}

int main(){
    cin >> h >> w >> t;

    rep(i,h){
        rep(j,w){
            cin >> M[i][j];
            if(M[i][j] == 'S') s= point{j,i};
            else if(M[i][j] == 'G') g= point{j,i};
        }
    }

    int right = 1000000000, left = 0;
    while(right - left > 1){
        int mid = (right + left ) / 2;
        if(bfs(mid)) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
