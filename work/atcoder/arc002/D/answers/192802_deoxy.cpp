#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
using namespace std;
typedef long long lli;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<vector<lli> > mat;
typedef vector<vector<bool> > matb;
typedef vector<string> vst;
typedef array<lli,3> ar;
typedef pair<vector<lli>,vector<lli> > pvv;
typedef vector<pvv>::iterator v_itr;

lli h,w;
char c[2001][2001];
lli ans_o = 0,ans_x = 0;
lli min_o,min_x,lim = 1ll << 62;
vector<pvv> a;
vector<v_itr> a_itr;
bool player = true;



void calc(pvv a){
    if(a.first.empty() || a.second.empty()){
        if(a.first.empty() && a.second.empty()) return;
        else if(a.first.empty()){
            min_x = min(min_x,a.second.front());
        }else if(a.second.empty()){
            min_o = min(min_o,w - a.first.back() - 1);
        }
        return;
    }
    lli o_top = a.first.back(),x_top = a.second.front();
    //cout << o_top << " " << x_top << endl;
    lli shift = (x_top - o_top) / 2;
    if((x_top - o_top) % 2 == 0){
        x_top -= shift - 1;
        o_top += shift - 1;
    }else{
        if(player){
            x_top -= shift - 1;
            o_top += shift;
            player = false;
        }else{
            x_top -= shift;
            o_top += shift - 1;
            player = true;
        }
    }
    lli t = a.first.size();
    for(lli i = 0;i < t;i++){
        ans_o += o_top - a.first[i];
    }
    ans_o -= t * (t - 1) / 2;
    t = a.second.size();
    for(lli i = 0;i < t;i++){
        ans_x += a.second[i] - x_top;
    }
    ans_x -= t * (t - 1) / 2;
}

void solve(){
    min_o = min_x = lim;
    for(lli i = 0;i < h;i++){
        char last = 'o';
        a.push_back(pvv());
        for(lli j = 0;j < w;j++){
            if(c[i][j] == 'o'){
                if(last != 'o'){
                    a.push_back(pvv());
                }
                a.back().first.push_back(j);
                last = 'o';
            }
            if(c[i][j] == 'x'){
                a.back().second.push_back(j);
                last = 'x';
            }
        }
    }
    for(auto itr = a.begin();itr != a.end();itr++){
        a_itr.push_back(itr);
    }
    sort(a_itr.begin(),a_itr.end(),[](v_itr a,v_itr b){
        return a->first.size() + a->second.size() > b->first.size() + b->second.size();
    });
    for(lli i = 0;i < a_itr.size();i++){
        calc(*(a_itr[i]));
    }
    if(min_o < lim || min_x < lim){
        //cout << min_o << " " << min_x << endl;
        if(min_o <= min_x) cout << "o" << endl;
        else cout << "x" << endl;
        return;
    }
    //cout << ans_o << " " << ans_x << endl;
    if(ans_o > ans_x) cout << "o" << endl;
    else cout << "x" << endl;
}
void input(){
    scanf("%lld %lld",&h,&w);
    for(lli i = 0;i < h;i++){
        scanf("%s",c[i]);
    }
}

int main(){
    input();
    solve();
    return 0;
}
