#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

const int MAXN=2e5+5;

int N;
ll a[MAXN], pref[MAXN];

int main()
{
        cin >> N;
        for (int i=0; i<N; i++)
                cin >> a[i];

        pref[0]=0;
        for (int i=1; i<=N; i++)
                pref[i] = pref[i-1]+a[i-1];

        ll mn=abs(2*pref[1]-pref[N]);
        for (int i=1; i<=N-1; i++) {
                ll x = abs(2*pref[i]-pref[N]);
                mn = min(mn,x);
        }

        cout << mn << "\n";

}