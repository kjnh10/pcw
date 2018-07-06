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

int f[26];
int fs[27];
Mod dp[27][261];
int main()
{
    Factorial fact(6000);FactorialInv facti(fact);
    Combination comb(fact, facti);
    REP(i,26)
        cin>>f[i];
    REP(i,26)
        fs[i+1]=fs[i]+f[i];
    dp[0][0]=1;
    REP(i,26)
    {
        REP(j,261)//隣り合う数
        {
            if(dp[i][j]==0) continue;
            if(f[i]==0)
            {
                dp[i+1][j]=dp[i][j];
                continue;
            }
            for(int k=f[i];k>0;k--)//分割の数
            {
                for(int l=0;l<=min(k,j);l++)//減らす隣の数
                {
                    if(fs[i]-j+1<k-l) continue;
                    /*cout<<i<<j<<k<<l<<endl;
                    cout<<comb(fs[i]-j+1,k-l);
                    cout<<comb(j,l);
                    cout<<comb(f[i]-1,k-1)<<endl;*/
                    dp[i+1][j+(f[i]-k)-l]+=dp[i][j]*comb(fs[i]-j+1,k-l)*comb(j,l)*comb(f[i]-1,k-1);
                    //cout<<j+(f[i]-k)-l<<" "<<dp[i+1][j+(f[i]-k)-l]<<endl;
                }
            }
        }
    }
    cout<<dp[26][0]<<endl;
}