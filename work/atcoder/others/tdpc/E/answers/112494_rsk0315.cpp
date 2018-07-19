#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template <class T>
class multidim_array {
    size_t size_;
    vector<T> array;
    vector<size_t> bounds;
public:
    multidim_array(const vector<size_t> bounds={}, T init=T()):
        size_(1), bounds(bounds)
    {
        for (size_t bound: bounds)
            size_ *= bound;

        array.assign(size_, init);
    }
    T &operator [](const vector<size_t> &indices) {
        size_t i=0, index=0;
        for (size_t tmp: indices)
            (index *= bounds[i++]) += tmp;

        return array[index];
    }
    T &front() {
        return array[0];
    }
    size_t size() {
        return size_;
    }
};

class Indexer {
    size_t size_;
    int num_loops;
    vector<size_t> bounds, index;
public:
    Indexer(const vector<size_t> &bounds):
        size_(bounds.size()), num_loops(0), bounds(bounds), index(size_, 0)
    {}
    Indexer &operator ++() {
        for (size_t i=size_; i--;) {
            if (++index[i] < bounds[i]) {
                return *this;
            }

            index[i] = 0;
        }
        ++num_loops;
        return *this;
    }
    size_t &operator [](size_t i) {
        return index[i];
    }
    size_t size() {
        return size_;
    }
    vector<size_t>::iterator begin() {
        return index.begin();
    }
    vector<size_t> to_v() {
        return index;
    }
    int loops() {
        return num_loops;
    }
};

class CondCounter {
    using DigitFunc=function<size_t (size_t, size_t)>;
    using Condition=function<bool (vector<size_t>::iterator)>;
    vector<DigitFunc> funcs;
    vector<size_t> bounds;
    size_t length;
    int64_t mod;
    multidim_array<int64_t> dp;
public:
    CondCounter(int64_t mod): bounds{0, 2}, mod(mod) {}
    pair<int64_t, int64_t> count_up(const Condition &cond) {
        Indexer index(bounds);
        pair<int64_t, int64_t> res;
        for (index[0]=length; index[1]<1; ++index) {
            if (!cond(index.begin()+2)) continue;

            vector<size_t> eq(index.to_v()), lt=eq;
            lt[1] = 1;

            (res.first += dp[lt]) %= mod;
            (res.second += dp[eq]) %= mod;
        }

        (res.second += res.first) %= mod;
        return res;
    }
    void append(size_t bound, const DigitFunc &func) {
        bounds.emplace_back(bound);
        funcs.emplace_back(func);
    }
    void store(const string &number) {
        length = number.length();
        bounds[0] = length+1;
        dp = multidim_array<int64_t>(bounds, 0);
        --bounds[0];
        dp.front() = 1;

        for (Indexer index(bounds); !index.loops(); ++index) {
            size_t pos=index[0], tight=index[1];
            size_t ub=tight? 9:(number[pos]-'0');
            vector<size_t> prev(index.to_v());
            for (size_t d=0; d<=ub; ++d) {
                vector<size_t> next{pos+1, tight||d<ub};
                for (size_t i=0; i<funcs.size(); ++i)
                    next.emplace_back(funcs[i](index[i+2], d));

                (dp[next] += dp[prev]) %= mod;
            }
        }
    }
};

int main() {
    int D;
    scanf("%d", &D);

    char buf[16384];
    scanf("%s", buf);
    string N(buf);

    CondCounter counter(1e9+7);
    counter.append(D, [D](size_t s, size_t n)->size_t {return (s+n)%D;});
    counter.store(N);

    auto sat=[](const vector<size_t>::iterator v) {return v[0]==0;};
    pair<int64_t, int64_t> res=counter.count_up(sat);

    (res.second += 1e9+6) %= int64_t(1e9+7);

    printf("%lld\n", res.second);
    return 0;
}
