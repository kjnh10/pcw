#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	int brojac=0;
	ll broj=1;
	ll brojce=0;
	while(brojce<n)
	{
		brojce+=broj;
		brojac++;
		broj++;
	}
	cout<<brojac<<endl;

}