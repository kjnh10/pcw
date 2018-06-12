#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int x,y;
vector < int > mv[2];
bool is_possible(int ind, int M)
{
	int sm[9000];
	for(int i = 0 ; i < 9000;++i)
		sm[i] = 0;
	sm[0] = 1;
	int SM = 0;
	for(int i = (ind == 0? 1:0);  i< mv[ind].size();++i)
	{
		SM += mv[ind][i];
		for(int j = 8999;j>=mv[ind][i];--j)
			if(sm[j-mv[ind][i]] == 1)
				sm[j] = 1;
	}
	//cout << SM << ' ' << M << endl;
	if((M >=0 && SM < M) || (M < 0 && SM < -M) )
	return false;
	if((M >= 0 && ((SM-M)&1)==0 &&sm[(SM-M)/2]==1) || (M < 0 && ((-M+SM)&1) == 0 && sm[(-M+SM)/2]==1))
	return true;
	return false;
}
int main() {
	cin >> s;
	cin >> x >> y;

	int ind = 0, sm = 0;
	for(int i = 0 ; i < s.length();++i)
	{
		if(s[i]=='T')
		{
			if(i==0)
				mv[ind].push_back(0);
			if(sm != 0)
				mv[ind].push_back(sm);
			ind ^=1;	
			sm = 0;
			continue;
		}
		sm+=1;
	}
	if(sm!=0)
	mv[ind].push_back(sm);
	if(is_possible(0,x-mv[0][0]) && is_possible(1,y))
	cout << "Yes\n";
	else
	cout << "No\n";
	// your code goes here
	return 0;
}