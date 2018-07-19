#include<bits/stdc++.h>
using namespace std;
int main() 
{
	long long int a,b;
	cin>>a>>b;
	bool flag;
	if(a<=1 && b<=1)
	 flag=false;
	else
  	{
   	  if(a==0 || b==0)
	   flag=true;
   	  else
	  {
          if(a==b)
           flag=false;
          else
          { 
            if(llabs(a-b)==1)
             flag=false;
            else
             flag=true;
          }
	  }
	}
    if(flag)
     cout<<"Alice";
    else
     cout<<"Brown";
     return 0;
}
