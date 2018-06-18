#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii > iiii;

void solve();

int H,W;
vector<pii> P[2010];
vector<iiii> D;
pii S[2010];

int main()
{
    scanf("%d%d",&H,&W);
    for(int i = 0; i < H; i++)
    {
        S[i].first = S[i].second = 0;
        for(int j = 0; j < W; j++)
        {
            char c;
            scanf(" %c",&c);
            if(c == 'o')
            {
                P[i].push_back(make_pair(1,j));
                S[i].first = 1;
            }
            else if(c == 'x')
            {
                P[i].push_back(make_pair(0,j));
                S[i].second = 1;
            }
        }
    }
    solve();
    return 0;
}

void solve()
{
    int o_lenge = 10000,x_lenge = 10000;
    for(int i = 0; i < H; i++)
    {
        if(!P[i].size())
        {
            continue;
        }
        if(!(P[i][0].first))
        {
            x_lenge = min(x_lenge,P[i][0].second);
        }
        if(P[i][P[i].size() - 1].first)
        {
            o_lenge = min(o_lenge,W - 1 - P[i][P[i].size() - 1].second);
        }
    }
    if(o_lenge != 10000 || x_lenge != 10000)
    {
        if(o_lenge <= x_lenge)
        {
            printf("o\n");
        }
        else
        {
            printf("x\n");
        }
        return;
    }
    int o_time = 0,x_time = 0;
    for(int i = 0; i < H; i++)
    {
        if(!P[i].size() || !S[i].first || !S[i].second)
        {
            continue;
        }
        for(int j = 0; j < P[i].size(); j++)
        {
            if(!(P[i][0].first) || P[i][P[i].size() - 1].first)
            {
                continue;
            }
            int first = P[i][j].second;
            int cou1 = 0,cou2 = 0;

            iiii now;
            /*while(j < P[i].size() && P[i][j].first == 1)
            {
                o_time += P[i][j].second - first;
                cou1++;
                j++;
            }*/
            while(j < P[i].size() && P[i][j].first == 1)
            {
                o_time += (P[i][j].second - first) * cou1;
                first = P[i][j].second;
                cou1++;
                j++;
            }
            o_time -= cou1 * (cou1 - 1) / 2;
            now.first.first = cou1;
            now.first.second = P[i][j].second - P[i][j - 1].second - 2;
            now.second.first = cou1;
            first = P[i][j].second;
            while(j < P[i].size() && P[i][j].first == 0)
            {
                x_time += P[i][j].second - first;
                cou2++;
                j++;
            }
            x_time -= cou2 * (cou2 - 1) / 2;
            now.first.first += cou2;
            now.second.second = cou2;
            D.push_back(now);
            j--;
        }
    }
    sort(D.begin(),D.end());
    /*for(int i = 0; i < D.size(); i++)
    {
        printf("%d %d %d %d\n",D[i].first.first,D[i].first.second,D[i].second.first,D[i].second.second);
    }*/
    //printf("%d %d\n",o_time,x_time);
    bool O = true;
    for(int i = D.size() - 1; i >= 0; i--)
    {
        if(D[i].first.second % 2)
        {
            if(O)
            {
                o_time += D[i].second.first;
            }
            else
            {
                x_time +=D[i].second.second;
            }
            O = !O;
        }
        o_time += D[i].second.first * (D[i].first.second / 2);
        x_time += D[i].second.second * (D[i].first.second / 2);
    }
    //printf("%d %d\n",o_time,x_time);
    if(o_time > x_time)
    {
        printf("o\n");
    }
    else
    {
        printf("x\n");
    }
    return;
}
