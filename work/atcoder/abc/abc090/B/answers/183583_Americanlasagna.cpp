#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,c=0;
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++)
        if(i%10==i/10000&&i/10%10==i/1000%10)
            c++;
    printf("%d",c);
    return 0;
}
