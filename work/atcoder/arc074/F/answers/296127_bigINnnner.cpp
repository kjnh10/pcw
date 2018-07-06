#include <functional>
#include <limits>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <new>
#include <array>
#include <utility>
#include <iterator>
#include <map>
namespace XX
{

    template<int BLOCKSIZE, int INITBUF = 1 << 20>
    class MemoryManager
    {
        public:
            static constexpr const int INIT = INITBUF / BLOCKSIZE;

            static MemoryManager* inst()
            {
                static MemoryManager ret;
                return &ret;
            }
            
            void* alloc()
            {
                void* ret;
                if(_ptr)
                {
                    ret = _ptr;
                    _ptr = *static_cast<void**>(_ptr);
                }
                else 
                {
                    if(_pos == _size) 
                    {
                        _pos = 0;
                        _buf[++_idx] = new char[std::max(_size <<= 1, 1)];
                    }

                    ret = _buf[_idx] + _pos;
                    _pos += BLOCKSIZE;
                }

                return ret;
            }

            void dealloc(void* p)
            {
                *static_cast<void**>(p) = _ptr;
                _ptr = p;
            }

            ~MemoryManager()
            {
//                for(int i = 1; i <= _idx; i++)
//                    delete []_buf[i];
            }

        private:

            MemoryManager() { _buf[0] = _init; }

            char _init[INIT * BLOCKSIZE];
            int _size = INIT * BLOCKSIZE;
            int _idx = 0;
            int _pos = 0;
            char* _buf[32] = {};
            void* _ptr = nullptr;
    };

    template<typename T>
    struct BlockAllocater
    {
        void* operator new(std::size_t count) { return MemoryManager<sizeof(T)>::inst()->alloc(); }
        void operator delete(void* ptr) { return MemoryManager<sizeof(T)>::inst()->dealloc(ptr); }
    };
    template<typename T>
    struct NullNode
    {
        static T nullnode;
        static T* null() { return &nullnode; }
        bool isNull(){return this == null();}
    };

    template<typename T>
    T NullNode<T>::nullnode;
}




namespace XX
{
    template<typename... EdgeTs>
    struct Graph
    {    
        public:
            struct Edge: public EdgeTs...
            {
                int from, to;
                Edge(int f, int t, EdgeTs... args) :from(f), to(t), EdgeTs(args)...  {}
                Edge(){}
            };

            struct Node:public Edge, BlockAllocater<Node>
            {
                Node* next;
                template<typename... Args> Node(Node* nn, Args... args) :next(nn),Edge(args...) {}
            };

            typedef Node* EdgeIdx;

            std::vector<Node*> adjlist;
            int numVertex;

            void _dealloc(Node* node) { if(node) { _dealloc(node->next); delete node; } }

            Graph(int v = 0) :adjlist(v) {}
            ~Graph(){for(Node* node: adjlist)_dealloc(node);}

            int size(){return adjlist.size();}
            void resize(int size){adjlist.resize(size);}
            EdgeIdx add(int from, int to, EdgeTs... args) { return adjlist[from] = new Node{adjlist[from], from, to, args...}; }

            Node& operator[](EdgeIdx idx){return idx->e;}
            struct Enumerator
            {
                struct It
                {
                    Node* ptr;
                    Node& operator*(){return *ptr;}
                    void operator++(){ptr = ptr->next;}
                    bool operator!=(const It& other){return ptr != other.ptr;}
                }b, e;
                It begin(){return b;}
                It end(){return e;}
            };
            struct AllEnumerator
            {
                struct It
                {
                    Node* ptr;
                    int v;
                    Graph& g;
                    Node& operator*(){return *ptr;}
                    void operator++()
                    {
                        ptr = ptr->next; 
                        while(!ptr && ++v < g.size())
                            ptr = g.adjlist[v];
                    }
                    bool operator!=(const It& other){return ptr != other.ptr;}
                };
                Graph& g;
                It begin()
                {
                    for(int i = 0; i < g.size(); i++)
                        if(g.adjlist[i])
                            return {g.adjlist[i], i, g};
                    return end();
                }
                It end(){return {nullptr, 0, g};}
            };
            Enumerator adj(int v) { return {adjlist[v], nullptr}; }
            Enumerator adj(EdgeIdx idx) { return {idx, nullptr}; }
            AllEnumerator edges() { return {*this}; }
            Enumerator operator[](int idx){return adj(idx);}
    };
}





struct Range
{   
    struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
    Range(int ee):b(0),e(ee){}
    Range(int bb, int ee):b(bb), e(ee){}
    It begin(){return {b, (b < e? 1: -1)};}
    It end(){return {e, 0};}
    int b, e;
};

template<typename T> inline T& UMAX(T& x, T y){if(x < y)x = y; return x;}
template<typename T> inline T& UMIN(T& x, T y){if(y < x)x = y; return x;}
template<typename T, typename... Args> struct ArithmiticPromotion { typedef decltype(T() + typename ArithmiticPromotion<Args...>::type()) type; };
template<typename T, typename U> struct ArithmiticPromotion<T, U> { typedef decltype(T() + U()) type; };
template<typename T> struct ArithmiticPromotion<T, T> { typedef T type; };
template<typename T> struct ArithmiticPromotion<T> { typedef T type; };
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MAX(T a, U b) { return a < b? b: a; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MAX(T a, Args... args) { return MAX(a, MAX(args...)); }
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MIN(T a, U b) { return a < b? a: b; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MIN(T a, Args... args) { return MIN(a, MIN(args...)); }



namespace XX
{
    template<typename T>
    struct FlowEdge
    {
        T cap;
        T flow;
        FlowEdge* rev;
    };

    template<typename T>
    struct CostEdge
    {
        T cost;
    };

    template<typename T = int, typename... EdgeTs>
    class FlowGraph:public Graph<FlowEdge<T>, EdgeTs...>
    {
        public:
            using Base = Graph<FlowEdge<T>, EdgeTs...>;
            using Graph<FlowEdge<T>, EdgeTs...>::Graph;
            using typename Base::EdgeIdx;

            EdgeIdx add(int from, int to, T cap, EdgeTs... args)
            {
                EdgeIdx x = Base::add(from, to, {cap, 0}, args...);
                EdgeIdx y = Base::add(to, from, {0, 0}, args...);
                x->rev = y;
                y->rev = x;
                return x;
            }

            void clear()
            {
                for(auto& e: this->edges())
                    e.flow = 0;
            }

            T flow(int from)
            {
                T ret = T();
                for(auto& e: this->adj(from))
                    ret += e.flow;
                return ret;
            }
    };


}
using XX::FlowGraph;


template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(char*,"%s")DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(unsigned int, "%u")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
int RD(char* arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename T> void WT(T arg) {std::printf(ScanfSpecifier<T>::value, arg); }
template<typename T, typename U> void WT(std::pair<T, U> arg) {std::printf("("); WT(arg.first); std::printf(", "); WT(arg.second); std::printf(")");}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), WT(args), 0)...}; }

template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}

#define _M_VARGS_NUM_IMPL(_1, _2, _3, _4, _5, _6, N, ...) N
#define _M_VARGS_NUM(...) _M_VARGS_NUM_IMPL(__VA_ARGS__, 6, 5, 4, 3, 2, 1)
#define _W1(_1) (#_1[0] == '"' || #_1[0] == '\''? WT("", _1, ""): WT('[', #_1, '=', _1, ']'))
#define _W2(_1, _2) (_W1(_1), _W1(_2))
#define _W3(_1, _2, _3) (_W1(_1), _W2(_2, _3))
#define _W4(_1, _2, _3, _4) (_W1(_1), _W3(_2, _3, _4))
#define _W5(_1, _2, _3, _4, _5) (_W1(_1), _W4(_2, _3, _4, _5))
#define _WW_IMPL2(num, ...) _W ## num(__VA_ARGS__)
#define _WW_IMPL(num, ...) _WW_IMPL2(num, __VA_ARGS__)
#define WW(...) (std::printf("(%03d) ", __LINE__), _WW_IMPL(_M_VARGS_NUM(__VA_ARGS__), __VA_ARGS__), WTL(""))


namespace XX
{
    namespace DinicMaxflow
    {
        template<typename T = int, typename... EdgeTs>
                FlowGraph<T, EdgeTs...>& maxflow(FlowGraph<T, EdgeTs...>& g, int from, int to)
                {
                    using EdgeIdx = typename FlowGraph<T, EdgeTs...>::EdgeIdx;
                    int N = g.size();
                    std::vector<int> dist(N);
                    std::queue<int> que;
                    std::vector<int> table(N + 2);
                    std::vector<EdgeIdx> next(N);
                    que.push(to);
                    dist[to] = 1;
                    table[1] = 1;
                    for(int step = 2; que.size(); step++)
                        for(int z = que.size(); z > 0; z--)
                        {
                            int u = que.front();
                            que.pop();
                            for(auto& e: g[u])
                                if(e.rev->cap - e.rev->flow && !dist[e.to])
                                {
                                    dist[e.to] = step;
                                    table[step]++;
                                    que.push(e.to);
                                }
                        }

                    bool finish = !dist[from];
                    std::function<T(int,T)> dfs = [&](int u, T minf) -> T
                    {
                        if(u == to)
                            return minf;
                        else
                        {
                            auto iter = next[u]? g.adj(next[u]): g[u];
                            for(auto& e: iter)
                                if(e.cap - e.flow && dist[u] == dist[e.to] + 1)
                                {
                                    T res = dfs(e.to, std::min(minf, e.cap - e.flow));
                                    if(res)
                                    {
                                        next[u] = &e;
                                        e.flow += res;
                                        e.rev->flow -= res;
                                        return res;
                                    }
                                }
                            int inc = N ;
                            for(auto& e: g[u])
                                if(e.cap - e.flow)
                                     UMIN(inc, dist[e.to]);
                            next[u] = EdgeIdx();

                            if(--table[dist[u]] == 0)
                                finish = true;
                            ++table[dist[u] = inc + 1];
                            return 0;
                        }
                    };
                    while(!finish && dist[from] != N + 1)
                        dfs(from, std::numeric_limits<T>::max());
                    return g;
                }
    }
}






//alias
using XX::Graph;
using RG = Range;
using XX::DinicMaxflow::maxflow; //(g, from, to)
//RD[L],RDV[L],WT[L],WTV[L] for i/o
//template
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int ll;

int main()
{
    int H, W;
    RD(H, W);


    FlowGraph<> g(H + W + 2);
    int f = H + W;
    int t = f + 1;

    int sx, sy, tx, ty;

    for(int i: RG(H))
        for(int j: RG(W))
        {
            char c;
            RD(c);

            if(c == 'o')
            {
                g.add(i, H + j, 1);
                g.add(H + j, i, 1);
            }
            if(c == 'S')
                sx = i, sy = j;
            if(c == 'T')
                tx = i, ty = j;
        }

    g.add(f, sx, H * W * 2);
    g.add(f, H + sy, H * W * 2);
    g.add(tx, t, H * W * 2);
    g.add(H + ty, t, H * W * 2);



    int ans = maxflow(g, f, t).flow(f);

    if(ans > H * W)
        WTL(-1);
    else
        WTL(ans);

}




