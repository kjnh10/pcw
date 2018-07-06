#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    set<int> st;
    for(int i=0;i<n;++i){
        int a;
        scanf("%d ",&a);
        while((a&1)!=1)a>>=1;
        st.insert(a);
    }
    printf("%d\n",st.size());

    return 0;
}
