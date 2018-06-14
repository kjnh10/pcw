#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double max_dis=0;
    cin>>n;
    pair<int,int> point[n];
    for(int i=0; i<n; i++){
        cin>>point[i].first>>point[i].second;
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            max_dis=max(max_dis,sqrt(pow(point[i].first-point[j].first,2)+pow(point[i].second-point[j].second,2)));
        }
    }
    printf("%f\n",max_dis);
    return 0;
}
