#include <bits/stdc++.h>
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
// VAR(int, x);
#define VAR(type, ...)type __VA_ARGS__;Scan(__VA_ARGS__);
template<typename T> void Scan(T& t){std::cin >> t;}
template<typename First,typename...Rest>void Scan(First& first,Rest&...rest){std::cin>>first;Scan(rest...);}
#define OUT(d) std::cout<<(d);
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<(d);
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<(d);
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
#define PAIR std::pair<int, int>
#define IN(a0, y, a1, b0, x, b1) (a0<=y && y<a1 && b0<=x && x<b1)
#define SHOW(d) {std::cout << #d << "\t:" << d << "\n";}
#define SHOWVECTOR(v) {std::cout << #v << "\t:";for(const auto& i : v){std::cout << i << " ";}std::cout << "\n";}
#define SHOWVECTOR2(v) {std::cout << #v << "\t:\n";for(const auto& i : v){for(const auto& j : i){std::cout << j << " ";}std::cout << "\n";}}
#define SHOWPAIRVECTOR(v) {for(const auto&& i:v){std::cout<<'('<<i.first<<", "<<i.second<<") ";}std::cout<<"\n";}
#define CHECKTIME(state) {auto start=std::chrono::system_clock::now();state;auto end=std::chrono::system_clock::now();auto res=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();std::cerr<<"[Time:"<<res<<"ns  ("<<res/(1.0e9)<<"s)]\n";}

//#define int ll
using ll = long long;
constexpr ll INF = 1LL<<60;

signed main(){
    INIT;
    CHECKTIME(([&]
    {
        VAR(std::string, s);
        std::string ss = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
        REP(i, 12){
            if(ss.substr(i, 20)==s){
                switch(i){
                    case  0: OUT("Do")BR; break;
                    case  2: OUT("Re")BR; break;
                    case  4: OUT("Mi")BR; break;
                    case  5: OUT("Fa")BR; break;
                    case  7: OUT("So")BR; break;
                    case  9: OUT("La")BR; break;
                    case 11: OUT("Si")BR; break;
                }
                break;
            }
        }
    }
    ()));
    return 0;
}

