#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b;cin>>n>>a>>b;
    int s[n];
    double p,q,sum;
    for(int i=0; i<n; i++){
        cin>>s[i];
        sum+=s[i]/(double)n;
    }
    int maxi=*max_element(s,s+n),
                    mini=*min_element(s,s+n);
    if(maxi==mini)cout<<-1<<endl;
    else{
        p=b/((double)(maxi-mini));
        q=a-sum*p;
        printf("%.7f %.7f\n",p,q);
    }
    return 0;
}
