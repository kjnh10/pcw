#include<cstdio>
#define mod 1000000007
using namespace std;

int main(void){
    int n;
    char s1[55];
    char s2[55];
    scanf("%d",&n);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    long long ans=1;
    int before=0;
    for(int i=1;i<=n;i++){
        if(s1[i]==s2[i]){
            if(before==0)ans*=3;
            else if(before==2)ans*=1;
            else if(before==1)ans*=2;
            before=1;
        }else{
            if(before==0)ans*=6;
            else if(before==1)ans*=2;
            else if(before==2)ans*=3;
            before=2;i++;
        }
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}
