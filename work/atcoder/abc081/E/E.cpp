#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
// 変数ダンプ先。coutかcerr{{{
#define DUMPOUT cerr
 
// 提出時はコメントアウト
#define DEBUG_
 
#ifdef DEBUG_
#define DEB
#else
// DEB と打つとデバッグ時以外はコメントアウトになる
#define DEB /##/
#endif
 
// 変数ダンプ用マクロ。デバッグ時以外は消滅する
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DEB DUMPOUT<<"  "; \
DUMPOUT<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
DUMPOUT<<"    "; \
dump_func(__VA_ARGS__)
 
// デバッグ用変数ダンプ関数
void dump_func() {
    DUMPOUT << endl;
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
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}/*}}}*/
 
int main(void) {
    int num = 2;
    double pi = 3.14;
    int d[5] = {};
    string str = "str";
    vector<int> vec{ 1,1,2,3 };
 
    dump(num, pi, str, vec, d);
 
    return 0;
}
