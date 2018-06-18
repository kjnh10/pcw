#include<bits/stdc++.h>
using namespace std;

string in;
int tot[55][55];

int main()
{
	int n;
	scanf("%d",&n);
	string ans = "";
	for(int a=0;a<n;a++)
	{
		cin>>in;
		int len = in.length();
		for(int b=0;b<len;b++)
		tot[a][in[b]-'a']++;
	}
	for(int a=0;a<26;a++)
	{
		int maxi;
		for(int b=0;b<n;b++)
		{
			if(b==0) maxi = tot[b][a];
			maxi = min(maxi,tot[b][a]);
		}
		for(int b=0;b<maxi;b++) ans+=(a+'a');
	}
	cout<<ans<<endl;
	
	
}