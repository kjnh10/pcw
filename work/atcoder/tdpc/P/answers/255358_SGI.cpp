#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()

const double eps=1e-5;
const LL INF=1e15;

class Mod
{
    private:
        static const long long MODULO = 1e9+7;
        long long value;

        const void Normalize()
        {
            value=value<0?(value%MODULO+MODULO):(value%MODULO);
        }

    public:
        Mod():value(0){}
        Mod(const long long &val)
        {
            value=val;
            Normalize();
        }
        
        explicit operator long long () const
        {
            return value;
        }

        const Mod operator -() const
        {
            return Mod(MODULO - value);
        }
        const Mod operator +(const Mod &rhs) const
        {
            return Mod(value + rhs.value);
        }
        const Mod operator -(const Mod &rhs) const
        {
            return Mod(value + (-rhs).value);
        }
        const Mod operator *(const Mod &rhs) const
        {
            return Mod(value * rhs.value);
        }
        Mod &operator +=(const Mod &rhs)
        {
            return *this = *this + rhs;
        }
        Mod &operator -=(const Mod &rhs)
        {
            return *this = *this - rhs;
        }
        Mod &operator *=(const Mod &rhs)
        {
            return *this = *this * rhs;
        }


        Mod pow(long long p) const;

        Mod inv() const
        {
            return pow(MODULO-2);
        }

        const Mod operator /(const Mod &rhs) const
        {
            return *this * rhs.inv();
        }
        Mod &operator /=(const Mod &rhs)
        {
            return *this = *this / rhs;
        }        
        bool operator ==(const Mod &rhs)
        {
            return value == rhs.value;
        }
};

Mod Mod::pow(long long p) const
{
    Mod tmp=1, mult=*this;
    while(p)
    {
        if((p&1)>0) tmp*=mult;
        p>>=1;
        mult*=mult;
    }
    return tmp;
}

namespace std
{
    ostream& operator<<(ostream& os, const Mod mod)
    {
        os<<(long long)mod;
        return os;
    }
};

class Factorial
{
    private:
        vector<Mod> ary;
    public:
        explicit Factorial(const size_t size):ary(vector<Mod>(size))
        {
            ary[0]=1;
            for(size_t i=1;i<size;i++)
                ary[i]=ary[i-1]*i;
        }

        size_t size() const {   return ary.size();  }

        Mod operator[] (const int id) const
        {
            return ary[id];
        }
};
class FactorialInv
{
    private:
        vector<Mod> ary;
    public:
        explicit FactorialInv(const Factorial &fact):ary(vector<Mod>(fact.size()))
        {
            for(size_t i=0;i<ary.size();i++)
                ary[i]=fact[i].inv();
        }

        //FactorialInv& operator=(FactorialInv&&)=default;

        Mod operator[] (const int id) const
        {
            return ary[id];
        }
};

class Combination
{
    private:
        const Factorial *fact;
        const FactorialInv *fact_inv;
    public:
        Combination(const Factorial &fact_, const FactorialInv &fact_inv_):fact(&fact_),fact_inv(&fact_inv_)
        {}

        Mod operator()(const int n, const int m) const
        {
            return (*fact)[n] * (*fact_inv)[m] * (*fact_inv)[n-m];
        }
};


int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n+1);
    REP(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    g[0].push_back(1);

    vector<vector<vector<Mod>>> memo(n+1, 
        vector<vector<Mod>>(51,vector<Mod>(3))); 
    function<void(int,int)> dfs=[&](int v, int pv)
    {
        vector<vector<Mod>> m(51,vector<Mod>(3)),pm(51,vector<Mod>(3)); 
        m[0][0]=1;
        for(auto&& e:g[v])
        {
            if(e==pv)continue;
            dfs(e,v);
            copy(ALL(m), pm.begin());

            REP(i,51)
            REP(j,3)
                m[i][j]=0;

            /*REP(i,51)
                m[i][2]=pm[i][2];*/

            REP(i,51)
            REP(j,51)
            {
                if(i+j>50)continue;
                m[i+j][0]+=pm[j][0] * memo[e][i][0];
                m[i+j][2]+=pm[j][2] * memo[e][i][0];
                //m[i+j][1]+=pm[j][0] * memo[e][i][0];
                if(i+j+1<=50)
                {
                    m[i+j+1][2]+=pm[j][1] * memo[e][i][1];
                    //m[i+j+1][1]+=pm[j][1] * memo[e][i][0];
                    //m[i+j+1][1]+=pm[j][0] * memo[e][i][1];
                }
                m[i+j][1]+=pm[j][1] * memo[e][i][0];
                m[i+j][1]+=pm[j][0] * memo[e][i][1];
            }
        }
        //    m[0][0]=1;
        copy(ALL(m),memo[v].begin());

        REP(i,51)
        {
            memo[v][i][0]+=m[i][2];
            if(i+1<=50)
                memo[v][i+1][0]+=m[i][1];
            memo[v][i][1]+=m[i][0];
        }
       //memo[v]=m;
    };

    dfs(0,-1);
    /*REP(i,n)
    cout<<memo[i+1][0][0]<<" "<<memo[i+1][0][1]<<endl;
    REP(i,n)
    cout<<memo[i+1][1][0]<<" "<<memo[i+1][1][1]<<endl;*/
    cout<<memo[1][k][0]<<endl;
}