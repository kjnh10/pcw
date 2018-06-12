#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    long long ans=0;
    long long sum=0;
    int min_ans=1000000007;
    for (i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a>b)
        {
            sum+=a-b;
            ans+=a;
            min_ans=min(min_ans,b);
        }
        else
        {
            ans+=a;
        }
    }
    if (min_ans==1000000007)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<ans-min_ans<<endl;
    return 0;
} 
