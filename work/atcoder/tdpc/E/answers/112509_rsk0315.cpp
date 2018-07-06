#include <cstdio>
#include <vector>
#include <functional>
#include <cstdint>
#include <string>
#include <utility>
 
using namespace std;
 
class DigitDP {
    using Func=function<size_t (size_t, size_t)>;
    vector<Func> funcs;
    vector<size_t> ubs;
    size_t size, numfuncs, n;
    int64_t mod;
    vector<int64_t> dp;
    void modify_table(
        const string &number, size_t pos, size_t tight, vector<int64_t> &dp,
        vector<size_t> &indices, size_t depth=0
    ) {
        if (depth == numfuncs) {
            size_t ub=tight? 9:(number[pos]-'0');
            for (size_t d=0; d<=ub; ++d) {
                size_t next=pos+1, prev=pos;
                (next <<= 1) |= (tight || d < ub);
                (prev <<= 1) |= tight;
 
                for (size_t i=0; i<numfuncs; ++i) {
                    (next *= ubs[i]) += funcs[i](indices[i], d);
                    (prev *= ubs[i]) += indices[i];
                }
 
                (dp[next] += dp[prev]) %= mod;
            }
            return;
        }
 
        for (indices[depth]=0; indices[depth]<ubs[depth]; ++indices[depth])
            modify_table(number, pos, tight, dp, indices, depth+1);
    }
    template <class Functor>
    void lookup_table(
        vector<size_t> &indices, Functor satisfies,
        pair<int64_t, int64_t> &res, size_t depth=0
    ) {
        if (depth == numfuncs) {
            if (!satisfies(indices)) return;
 
            size_t eq=(n<<1), lt=(n<<1|1);
            for (size_t i=0; i<depth; ++i) {
                (lt *= ubs[i]) += indices[i];
                (eq *= ubs[i]) += indices[i];
            }
 
            (res.first += dp[lt]) %= mod;
            (res.second += dp[eq]) %= mod;
            return;
        }
 
        for (indices[depth]=0; indices[depth]<ubs[depth]; ++indices[depth])
            lookup_table(indices, satisfies, res, depth+1);
    }
public:
    DigitDP(int64_t mod): size(2), numfuncs(0), mod(mod) {}
    template <class Functor>
    pair<int64_t, int64_t> count_up(Functor satisfies) {
        vector<size_t> indices(numfuncs);
 
        pair<int64_t, int64_t> res;  // <lt, le>
        lookup_table(indices, satisfies, res);
        (res.second += res.first) %= mod;
        return res;
    }
    void append(size_t ub, const Func &&func) {
        size *= ub;
        ++numfuncs;
        ubs.push_back(ub);
        funcs.push_back(func);
    }
    void store(const string &number) {
        n = number.length();
        dp.assign(size*(n+1), 0); dp[0]=1;
        vector<size_t> indices(numfuncs);
 
        for (size_t pos=0; pos<n; ++pos)
            for (size_t tight=0; tight<2; ++tight)
                modify_table(number, pos, tight, dp, indices);
    }
};
 
int64_t count(const string &N, size_t D, int64_t mod=1e9+7) {
    DigitDP d(mod);
 
    d.append(D, [D](size_t k, size_t d)->size_t {
        return (k + d) % D;
    });
 
    int64_t res=0;
    auto satisfies=[](const vector<size_t> &v)->bool {
        return v[0] == 0;
    };
 
    d.store(N);
    res += d.count_up(satisfies).second;
    --res;
 
    return (res += mod) % mod;
}
 
int main() {
    int64_t D;
    scanf("%lld", &D);
    string N; {
        char tmp[16384];
        scanf("%s", tmp);
        N = tmp;
    }
 
    printf("%lld\n", count(N, D));
    return 0;
}
