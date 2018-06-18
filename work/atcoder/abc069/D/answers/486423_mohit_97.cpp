//If you are reading this then you are at wrong place.
#include<bits/stdc++.h>
#define mod 1000000007
#define lli long long int
using namespace std;
bool prime [1000001];
void debug(lli a){cout<<a<<endl;}
lli sieve(lli a){memset(prime,true,sizeof(prime));lli p,i;for(p=2;p*p<=a;p++){if(prime[p]==true){for(i=p*2;i<=a;i+=p)prime[i]=false;}}return 0;}
lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli find_max(lli __a,lli __b){return __a^((__a^__b) & -(__a<__b));}
lli add(lli __a,lli __b,lli MOD){lli x = (__a+__b)%MOD; return x; }
lli mul(lli a,lli b,lli MOD){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b,lli MOD){lli x = (a-b+MOD)%MOD; return x; }
lli div(lli a,lli b,lli MOD){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}
//97->a 122->z
//65-A
int main()
{
	//freopen("testcase.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
	
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);	
	cout.precision(20);
	lli t,i,j;
	//cin>>t;
	//memset(dp, -1, sizeof dp);
	t=1;
	lli counter1=0;
	while(t--)
	{
		counter1++;
		int n,m;
		cin>>n>>m;
		int n1;
		cin>>n1;
		int a[n1+1];
		for(i=1;i<=n1;i++)
			cin>>a[i];
		vector<int>answer;
		for(i=1;i<=n1;i++)
		{
			for(j=0;j<a[i];j++)
				answer.push_back(i);
		}
		i=0;
		j=0;
		int k=0;
		vector<int>answer1[101];
		int count1=0;
		while(1)
		{
			answer1[count1].push_back(answer[k]);
			//cout<<answer[k]<<" ";
			k++;
			i++;
			if(k==answer.size())
				break;
			if(i==m)
			{
				count1++;
				i=0;
				//cout<<endl;
			}
		}
		for(i=0;i<=count1;i++)
		{
			if(i%2==1)
				reverse(answer1[i].begin(),answer1[i].end());
			for(j=0;j<answer1[i].size();j++)
				cout<<answer1[i][j]<<" ";
			cout<<endl;
		}
		//cout<<"Case #"<<counter1<<" ";
		//cout<<endl;	
	}	
}
