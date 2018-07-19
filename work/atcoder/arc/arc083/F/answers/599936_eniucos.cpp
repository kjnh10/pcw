#include<bits/stdc++.h>

using namespace std;

int sz, N, fac[200009], inv[200009], fath[200009], ap[200009], q[200009], val[200009], cnt[200009];
vector < int > v[200009], sons[200009];
const int mod = 1e9 + 7;

int add (int x, int y) {int ans = x + y; if (ans >= mod) ans -= mod; return ans;}
int subtract (int x, int y) {if (x >= y) return x - y; return x - y + mod;}
int mul (int x, int y) {return 1LL * x * y % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int power (int a, int b)
{
    int p = 1;
    for (int i=0; (1<<i) <= b; i++)
    {
        if (b & (1 << i)) p = mul (p, a);
        a = mul (a, a);
    }
    return p;
}

void Prec (int lim){fac[0] = inv[0] = 1;for (int i=1; i<=lim; i++)fac[i] = mul (fac[i - 1], i);
inv[lim] = power (fac[lim], mod - 2);for (int i=lim - 1; i>=1; i--)inv[i] = mul (inv[i + 1], i + 1);}
int comb (int N, int K){int ans = mul (fac[N], inv[N - K]);ans = mul (ans, inv[K]);return ans;}

pair < int, int > combine (pair < int, int > a, pair < int, int > b)
{
    return {a.first + b.first, mul (mul (a.second, b.second), comb (a.first + b.first, a.first))};
}

pair < int, int > ways (int node)
{
    if (sons[node].empty ()) return {1, 1};
    pair < int, int > ans = {0, 1};///length, ways
    for (auto v : sons[node])
        ans = combine (ans, ways (v));
    ans.first ++;
    return ans;
}

vector < int > curr;
void ever (int i) {curr.push_back (i);}
void Clear () {for (auto i : curr) fath[i] = 0, sons[i].clear (); curr.clear ();}

void dfs (int nod, int tata)
{
    ever (nod);
    for (auto fiu : v[nod])
        if (fiu != tata && ap[fiu] == 1)
        {
            val[fiu] = nod, dfs (fiu, nod);
            if (fiu < val[nod])
                fath[fiu] = nod;
        }
}

pair < int, int > solve ()
{
    q[sz + 1] = q[1];
    for (int i=1; i<=sz; i++)
        if (q[i - 1] < q[i + 1])
            fath[q[i - 1]] = q[i];
    for (int i=1; i<=sz; i++)
        val[q[i]] = q[i + 1], dfs (q[i], -1);
    sort (curr.begin (), curr.end ());
    curr.erase (unique (curr.begin (), curr.end ()), curr.end ());
    for (auto it : curr)
    {
  //      printf ("(%d, %d) ", it, fath[it]);
        if (fath[it] != 0)
            sons[fath[it]].push_back (it);
    }
//    printf ("\n");
    pair < int, int > ans = {0, 1};
    for (auto it : curr)
        if (fath[it] == 0)
            ans = combine (ans, ways (it));
    Clear ();
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=2 * N; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y), y += N;
    v[x].push_back (y), v[y].push_back (x);
}
N += N, Prec (N + 1);
for (int i=1; i<=N; i++)
    if (v[i].size () == 0)
    {
        printf ("0\n");
        return 0;
    }
for (int i=1; i<=N; i++)
{
    cnt[i] = v[i].size ();
    if (cnt[i] == 1)
        q[++sz] = i, ap[i] = 1;
}
for (int i=1; i<=sz; i++)
    for (auto j : v[q[i]])
    {
        cnt[j] --;
        if (cnt[j] == 1)
            q[++sz] = j, ap[j] = 1;
    }
for (int i=1; i<=N; i++)
    if (ap[i] == 0 && cnt[i] != 2)
    {
        printf ("0\n");
        return 0;
    }
pair < int, int > ans = {0, 1};
for (int I=1; I<=N; I++)
    if (ap[I] == 0)
    {
        int sum = 0, L = 0;
        for (auto rd : v[I])
        if (ap[rd] == 0)
        {
            sz = 1, q[1] = I, q[0] = rd;
            for (int i=1;; i++)
            {
                q[i + 1] = 0;
                for (auto nxt : v[q[i]])
                    if (nxt != q[i - 1] && ap[nxt] == 0)
                    {
                        q[i + 1] = nxt;
                        break;
                    }
                if (q[i + 1] == 0)
                {
                    printf ("0\n");
                    return 0;
                }
                if (q[i + 1] == q[0])
                {
                    sz = i + 1;
                    break;
                }
            }
            pair < int, int > curr = solve ();
            adto (sum, curr.second), L = curr.first;
        }
        for (int i=1; i<=sz; i++)
            ap[q[i]] = 1;
        ans = combine (ans, {L, sum});
    }
printf ("%d\n", ans.second);
return 0;
}
