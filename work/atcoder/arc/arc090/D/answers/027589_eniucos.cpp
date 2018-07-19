#include<bits/stdc++.h>

using namespace std;

int N, M, ap[100009];
long long h[100009];
vector < pair < int, int > > v[100009];

void dfs (int nod)
{
    ap[nod] = 1;
    for (auto it : v[nod])
        if (ap[it.first] == 0)
            h[it.first] = h[nod] + it.second, dfs (it.first);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y, d;
    scanf ("%d %d %d", &x, &y, &d);
    v[x].push_back ({y, d});
    v[y].push_back ({x, -d});
}
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
        h[i] = 0, dfs (i);
for (int i=1; i<=N; i++)
    for (auto it : v[i])
        if (h[it.first] != h[i] + it.second)
        {
            printf ("No\n");
            return 0;
        }
printf ("Yes\n");
return 0;
}
