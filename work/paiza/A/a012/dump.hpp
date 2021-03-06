// http://www.creativ.xyz/dump-cpp-652

using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define DUMPOUT cerr // 変数ダンプ先。coutかcerr

#ifdef PCM
  #define dump(...) DUMPOUT<<"  "; \
    DUMPOUT<<#__VA_ARGS__; \
    DUMPOUT<<":=> "; \
    dump_func(__VA_ARGS__); DUMPOUT<<"in ["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;
  #define dump_1d(x,n) DUMPOUT <<"  " \
    <<#x<<"["<<#n<<"]"<<":=> {"; \
    rep(i,n){ DUMPOUT << x[i] << (((i)==(n-1))?"}":", "); } DUMPOUT <<" in [" << __LINE__ << "]" << endl;
  #define dump_2d(x,n,m) DUMPOUT <<"  " \
    <<#x<<"["<<#n<<"]"<<"["<<#m<<"]"<<":=> \n"; \
    rep(i,n)rep(j,m){ DUMPOUT << ((j==0)?"     |":" ") << x[i][j] << (((j)==(m-1))?"|\n":" "); } \
    DUMPOUT <<"  in [" << __LINE__ << "]" << endl;
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif

// デバッグ用変数ダンプ関数
void dump_func() {
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    }
    else {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

// vector出力
template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "{";
    for (int i = 0; i<sz(vec); i++) {
        os << vec[i] << (i + 1 == sz(vec) ? "" : ", ");
    }
    os << "}";
    return os;
}

// map出力
template<typename T, typename U>
ostream& operator << (ostream& os, const map<T, U>& ma) {
    os << "{";

    int cnt = 0;
    for (auto x: ma){
      cnt ++;
      os << x.first << ": " << x.second << (cnt==sz(ma) ? "" : ", ");
    }
    os << "}";
    return os;
}
