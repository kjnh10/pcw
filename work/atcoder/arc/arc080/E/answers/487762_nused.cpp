#include <bits/stdc++.h>
using namespace std;

int p[200005];
int pos[200005];

struct mintree
{
    int tree[524288];

    void init()
    {
        for (int i = 262143; i >= 1; i--) tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int get(int l, int r)
    {
        l += 262144; r += 262144;
        int ret = INT_MAX;
        while (l <= r)
        {
            if (l & 1) ret = min(ret, tree[l++]);
            if (!(r & 1)) ret = min(ret, tree[r--]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
} odd, even;

int main()
{
    memset(odd.tree, 0x7F, sizeof(odd.tree));
    memset(even.tree, 0x7F, sizeof(even.tree));

    int n;
    scanf("%d",&n);

    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) pos[p[i]] = i;
    for (int i = 1; i <= n; i += 2) odd.tree[i + 262144] = p[i];
    for (int i = 2; i <= n; i += 2) even.tree[i + 262144] = p[i];

    odd.init();
    even.init();

    priority_queue<tuple<int, int, int, int>> st;
    int X = odd.get(1, n); int Y = even.get(pos[X] + 1, n);
    st.emplace(-X, -Y, 1, n);

    while (st.empty() == false)
    {
        int v1, v2, lo, hi;
        tie(v1, v2, lo, hi) = st.top();
        v1 = -v1; v2 = -v2;
        st.pop();

        printf("%d %d ", v1, v2);

        v1 = pos[v1]; v2 = pos[v2];

        // lo ~ v1 ~ v2 ~ hi
        // lo ~ v1 - 1, v1 + 1 ~ v2 - 1, v2 + 1 ~ hi

#define F auto &a = (L & 1) ? odd : even; auto &b = (L & 1) ? even : odd; \
    int X = a.get(L, R); int Y = b.get(pos[X], R); st.emplace(-X, -Y, L, R);

        int L, R;

        if (lo < v1 - 1)
        {
            L = lo; R = v1 - 1; F
        }

        if (v1 + 1 < v2 - 1)
        {
            L = v1 + 1; R = v2 - 1; F
        }

        if (v2 + 1 < hi)
        {
            L = v2 + 1; R = hi; F
        }
    }

    printf("\n");
}

