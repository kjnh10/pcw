#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, nr, D, sol[20017], ap[20017], val[20017], solved[20017], Q[20017], x[20017], y[20017];
set < pair < int, int > > S;

int opus (int i)
{
    if (i > N) return i - N;
    return i + N;
}

void Read ()
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
        scanf ("%d %d", &x[i], &y[i]), val[i] = x[i], val[opus (i)] = y[i];
}

void Init ()
{
    S.clear ();
    sol[0] = 0;
    for (int i=1; i<=N; i++)
        S.insert (make_pair (x[i], i)), S.insert (make_pair (y[i], opus (i))), ap[i] = ap[i + N] = 0, solved[i] = solved[i + N] = 0, sol[i] = sol[i + N] = 0;
}

int getClose (int x, int nu_vreau)
{
    bool e = (S.find (make_pair (val[nu_vreau], nu_vreau)) != S.end ());
    auto it = S.lower_bound (make_pair (x, 0));
    while (it != S.end () && it->first - x < D)
    {
        if (solved[it->second] || it->second == nu_vreau)
        {
            auto it2 = it; it2 ++;
            S.erase (it);
            it = it2;
            continue;
        }
        if (e) S.insert (make_pair (val[nu_vreau], nu_vreau));
        return it->second;
    }
    it = S.lower_bound (make_pair (x, 0));
    if (it == S.begin ())
    {
        if (e) S.insert (make_pair (val[nu_vreau], nu_vreau));
        return -1;
    }
    it --;
    while (x - it->first < D)
    {
        if (solved[it->second])
        {
            if (it == S.begin ()) return -1;
            auto it2 = it; it2 --;
            S.erase (it);
            it = it2;
            continue;
        }
        if (e) S.insert (make_pair (val[nu_vreau], nu_vreau));
        return it->second;
    }
    if (e) S.insert (make_pair (val[nu_vreau], nu_vreau));
    return -1;
}

void dfs (int nod)
{
    ap[nod] = 1, solved[opus (nod)] = 1;
    if (S.find (make_pair (val[opus (nod)], opus (nod))) != S.end ())
        S.erase (S.find (make_pair (val[opus (nod)], opus (nod))));
    while (1)
    {
        int vecin = getClose (val[nod], nod);
        if (vecin == -1)
        {
            Q[++nr] = nod;
            return ;
        }
        //printf ("%d -> %d\n", nod, opus (vecin));
        dfs (opus (vecin));
    }
}

void dfp (int nod)
{
    solved[nod] = 1;
    if (S.find (make_pair (val[nod], nod)) != S.end ())
        S.erase (S.find (make_pair (val[nod], nod)));
    if (sol[nod] || sol[0] == -1)
    {
        sol[0] = -1;
        return ;
    }
    sol[opus (nod)] = 1, ap[nod] = 1;
    while (1)
    {
        int vecin = getClose (val[opus (nod)], opus (nod));
        if (vecin == -1) return ;
      //  printf ("%d <- %d\n", nod, vecin);
        dfp (vecin);
    }
}

bool ok (int minD)
{
    D = minD, nr = 0;
    Init ();
    for (int i=1; i<=2 * N; i++)
        if (ap[i] == 0)
            dfs (i);
    Init ();
    //printf ("\n");
    for (int i=nr; i>=1; i--)
        if (ap[Q[i]] == 0 && ap[opus (Q[i])] == 0)
            dfp (Q[i]);
    if (sol[0] == -1) return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
int p = 0, u = 1000000000, mij, ras = -1;
//printf ("%d\n", ok (5));
//return 0;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, p = mij + 1;
    else u = mij - 1;
}
printf ("%d\n", ras);

return 0;
}
