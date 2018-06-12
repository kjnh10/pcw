#include <cstdio>
#include <cstring>

typedef long long ll;
char data[20];
int n;

int main()
{
    scanf("%s", data);
    n=strlen(data);
    if(n == 1){
        puts(data);
        return 0;
    }
    int naka = 1<<(n-1);
    ll ans = 0;
    for(int i=0; i<naka; ++i){
        ll sum = 0;
        ll cur = 0;
        for(int j=0; j<n; ++j){
            cur = cur*10 + (data[j]-48);
            if((1&(i>>j)) || (j==n-1)) sum += cur, cur=0;
        }
        ans += sum;
    }
    printf("%lld\n", ans);
    return 0;
}
