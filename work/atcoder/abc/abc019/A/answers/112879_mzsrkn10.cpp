#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int ans;
    if(a<=b&&b<=c)ans = b;
    else if(a<=c&&c<=b)ans = c;
    else if(b<=a&&a<=c)ans = a;
    else if(b<=c&&c<=a)ans = c;
    else if(c<=a&&a<=b)ans = a;
    else if(c<=b&&b<=a)ans = b;
    printf("%d\n",ans);

    return 0;
}
