#include <bits/stdc++.h>
using namespace std;
#define LL long long
int ask(LL p)
{
    cout << "? " << p << endl;
    cout.flush();
    string s;
    cin >> s;
    if (s[0] == 'Y') return 1; else return 0;
}
void put(LL p)
{
    cout << "! " << p << endl;
    cout.flush();
    exit(0);
}
int main()
{
    if (ask(1000000000))
    {
        for (LL i = 1; ; i *= 10)
            if (ask(i * 2)) put(i);
    }
    else
    {
        for (LL i = 100000000; i >= 1; i /= 10)
            if (ask(i))
            {
                LL l = i + 1, r = i * 10 - 1;
                while (l < r)
                {
                    LL md = (l + r) / 2;
                    if (ask(md * 10 + 9)) r = md;
                    else l = md + 1;
                }
                put(l);
            }
    }
}
