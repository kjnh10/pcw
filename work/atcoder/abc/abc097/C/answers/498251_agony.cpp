#include<bits/stdc++.h>

using namespace std;

int main(){
        string s;
        cin>>s;
        int K;
        cin>>K;
        vector <string> a;
        for(int i=1;i<=min(5, (int)s.length());i++){
                for(int j=0;j<=(int)s.length()-i;j++){
                        string ss=s.substr(j, i);
                        bool flag=false;
                        for(int k=0;k<(int)a.size();k++){
                                if(ss==a[k]){
                                        flag=true;
                                        break;
                                }
                        }
                        if(flag){
                                continue;
                        }
                        if(a.size()<10){
                                a.push_back(ss);
                        }
                        else{
                                sort(a.begin(), a.end());
                                a[9]=ss;
                        }
                }
        }
        sort(a.begin(), a.end());
        /*for(int i=0;i<(int)a.size();i++){
                cout<<a[i]<<endl;
        }*/
        cout<<a[K-1]<<endl;
        return 0;
}
