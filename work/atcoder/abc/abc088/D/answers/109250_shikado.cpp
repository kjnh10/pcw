#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

char field[51][51];
int dist[51][51];

int main(){

    const int INF=1<<29;
    int H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++){
            cin >> field[i][j];
            dist[i][j] = INF;
        }


    queue<pii> q;
    q.push(pii(0, 0));
    dist[0][0] = 0;
    while(q.size()){
        pii p = q.front(); q.pop();
        int cy = p.first;
        int cx = p.second;
        int ccost = dist[cy][cx];
        const int dy[]={-1,0,0,1};
        const int dx[]={0,-1,1,0};
        for(int k = 0; k < 4; k++){
            int ny = cy + dy[k];
            int nx = cx + dx[k];
            if(ny>=0&&nx>=0&&ny<H&&nx<W&&dist[ny][nx]==INF&&field[ny][nx]=='.'){
                dist[ny][nx] = ccost + 1;
                q.push(pii(ny, nx));
            }
        }
    }

    if(dist[H-1][W-1] == INF){
        cout << -1 << endl;
    }
    else{
        int last_white_cnt =  dist[H-1][W-1] + 1;
        int fst_white_cnt = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(field[i][j]=='.'){
                    fst_white_cnt++;
                }
            }
        }
        cout << fst_white_cnt - last_white_cnt << endl;
    }
        
    

    return 0;
}
