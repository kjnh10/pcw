/*
ID: barish21
LANG: C++14
TASK: test
*/

/****Author: Barish Namazov****/
#include <bits/stdc++.h>

using namespace std;

/***TEMPLATE***/
#define intt long long

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define F first
#define S second
#define pb push_back

#define IO ios_base::sync_with_stdio(false);cin.tie();

const intt max1 = 11;
const intt max2 = 102;
const intt max3 = 1003;
const intt max4 = 10004;
const intt maxx = 200005;
const intt max6 = 1000006;
const intt max7 = 10000007;
const intt lg2 = 7;
const intt lg3 = 10;
const intt lg4 = 13;
const intt lg5 = 17;
const intt lg6 = 20;
const intt lg7 = 24;
const intt lg8 = 27;
const intt lg9 = 30;
const intt lg18 = 60;
const intt INF = 2LL * 1000000000;
/***************/

/***Additional Functions***/
intt powmod(intt a,intt b,intt mod){intt res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
intt gcd(intt a, intt b) { while(b) b ^= a ^= b ^= a %= b; return a;}
intt lcm(intt a,intt b){return a*b/gcd(a,b);}
intt is_prime(intt n){if(n==1)return 0;if(n==2)return 1;if(n%2==0)return 0;for(intt i=3;i<=sqrt(n);i+=2)if(n%i==0)return 0;return 1;}
intt is_integer(double n){if(floor(n)==ceil(n))return 1;return 0;}

intt sto_int(string s){stringstream ss(s);intt n;ss>>n;return n;}
string to_string(intt n){stringstream ss;ss<<n;string s=ss.str();return s;}
/**************************/

intt arr[maxx];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    IO;
    intt n;
    cin >> n;
    for (intt i = 1; i <= n; i++)
        cin >> arr[i];
    for (intt i = n; i >= 1; i -= 2)
        cout << arr[i] << " " ;
    for (intt i = (n % 2 == 0 ? 1 : 2); i <= n; i += 2)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
