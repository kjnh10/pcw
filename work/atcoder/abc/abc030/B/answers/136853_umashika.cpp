#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>12)n-=12;//[0:12)
    //時間を長針に変換して長針(本当は短針)と長針の角を求める
    double tmp1 = n*5+(double)m/12;
    double tmp2 = (double)m;
    double choshin1 = max(tmp1,tmp2);
    double choshin2 = min(tmp1,tmp2);
    double tmp3 = choshin1-choshin2;
    double ans = tmp3*6;
    if(ans>180.0)ans = 360.0-ans;

    //cout<<"choshin1 : "<<choshin1<<endl;
    //cout<<"choshin2 : "<<choshin2<<endl;
    printf("%.5lf\n",ans);
    return 0;
}