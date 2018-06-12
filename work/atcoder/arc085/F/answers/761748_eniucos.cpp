#include<bits/stdc++.h>

using namespace std;

int ansQ, N, M, s[200009], s0[200009], dp[200009], b[200009], aint[800009], pref[800009], lzy[800009];
vector < int > v[200009];

void Build (int nod, int st, int dr)
{
    aint[nod] = lzy[nod] = 1e8;
    if (st == dr) return ;
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    Build (f1, st, mij);
    Build (f2, mij + 1, dr);
}

void split (int nod, int f1, int f2)
{
    if (lzy[nod] == 1e8) return;
    lzy[f1] = min (lzy[f1], lzy[nod]), aint[f1] = min (aint[f1], lzy[nod]);
    lzy[f2] = min (lzy[f2], lzy[nod]), aint[f2] = min (aint[f2], lzy[nod]);
    lzy[nod] = 1e8;
}

void UpdateSegm (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        aint[nod] = min (aint[nod], val), lzy[nod] = min (lzy[nod], val);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (x <= mij) UpdateSegm (f1, st, mij, x, y, val);
    if (mij < y) UpdateSegm (f2, mij + 1, dr, x, y, val);
    aint[nod] = min (aint[f1], aint[f2]);
}

void Query (int nod, int st, int dr, int pos)
{
    if (st == dr)
    {
        ansQ = aint[nod];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    split (nod, f1, f2);
    if (pos <= mij) Query (f1, st, mij, pos);
    else Query (f2, mij + 1, dr, pos);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=2; i<=N + 1; i++)
    scanf ("%d", &b[i]), s[i] = s[i - 1] + b[i], s0[i] = s0[i - 1] + 1 - b[i];
scanf ("%d", &M);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y), x ++, y ++;
    v[y].push_back (x);
}
Build (1, 1, N + 1);
dp[1] = 0;
for (int i=2; i<=N + 1; i++)
{
    dp[i] = dp[i - 1] + b[i];
    vector < pair < pair < int, int >, int > > updates;
    for (auto lft : v[i])
    {
        int curr = pref[lft - 1] + s[lft - 1] + (s0[i] - s0[lft - 1]);
        ///lft <= j < i, dp[j] + s0[i] - s0[j]
        if (lft < i)
        {
            Query (1, 1, N + 1, lft);
            curr = min (curr, ansQ + s0[i]);
        }
        if (curr < dp[i]) dp[i] = curr;
        updates.push_back ({{lft, i}, curr - s0[i]});
    }
    for (auto u : updates)
        UpdateSegm (1, 1, N + 1, u.first.first, u.first.second, u.second);
    ///
    pref[i] = min (pref[i - 1], dp[i] - s[i]);
}
printf ("%d\n", dp[N + 1]);
return 0;
}
