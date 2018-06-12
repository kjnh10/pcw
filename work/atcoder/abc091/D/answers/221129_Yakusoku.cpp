#include<bits/stdc++.h>
using namespace std;


int a[200050];
int b[200050];
int one[200050];
int zer[200050];
int ok,zk;
int cal(int x,int y)
{
    int c1=lower_bound(one,one+ok,y)-one;
    int c2=lower_bound(zer,zer+zk,y)-zer;
    if(x)
    {
        int f1=ok-c1;
        int f2=c2;
        return f1+f2;
    }
    else
    {
        int f1=c1;
        int f2=zk-c2;
        return f1+f2;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        scanf("%d",b+i);
    int ans;
    for(int i=0;i<30;i++)
    {
        int f=1<<i;
        ok=zk=0;
        for(int j=0;j<n;j++)
        {
            int z=b[j]%f;
            if(b[j]&f)
                one[ok++]=z;
            else
                zer[zk++]=z;
        }
        sort(one,one+ok);
        sort(zer,zer+zk);
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            int temp=cal((a[j]>>i)&1,f-a[j]%f);
//            printf("%d\n",temp);
            cnt^=temp%2;
        }
        if(cnt)
            ans|=f;
    }
    printf("%d\n",ans);
	return 0;
}

