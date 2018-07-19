#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1100005, INF = 1<<25;

int in[N], n, cc[129];
bool used[N];
char str[N];
vector<int>g[129];

int lowbit(int t)
{
    return t&(t^(t-1));
}

int sum(int end)
{
    int ans=0;
    while(end>0)
    {
        ans+=in[end];
        end-=lowbit(end);
    }
    return ans;
}

void add(int pos ,int num)
{
    while(pos<=n)
    {
        in[pos]+=num;
        pos+=lowbit(pos);
    }
}

void solve()
{
    memset(in, 0, sizeof(in));
    for(int i=1; i<=n+1; i++)
    {
        add(i,1);
    }
    LL ans = 0;
    int v, u, size;
    char s;
    memset(used, 0, sizeof(used));
    for(int i=1; i<=n; i++)
    {
        if(!used[i])
        {
            s = str[i];
            size = g[s].size();
            u = g[s][size-1];
            if(i == u)
            {
                ans += (sum(n) - sum(i))/2;
            }
            else
            {
                ans += sum(n) - sum(u);
            }
            add(u, -1);
            add(i, -1);
            used[i] = used[u] = 1;
            g[s].erase(g[s].end()-1);
        }
    }
    printf("%lld", ans);
    puts("");
}

int main()
{
    scanf("%s", str+1);
        n = strlen(str+1);
        memset(cc, 0, sizeof(cc));

        for(int i=1; i<129; i++)
            g[i].clear();

        for(int i=1; i<=n; i++)
        {
            cc[str[i]]++;
            g[str[i]].push_back(i);
        }

        int flag = 0;
        for(int i=0; i<26; i++)
        {
            if(cc['a'+i]%2) flag++;
            if(cc['A'+i]%2) flag++;
        }
        if(flag > 1)
        {
            printf("-1");
            puts("");
        }
        else
        {
            solve();
        }
    return 0;
}