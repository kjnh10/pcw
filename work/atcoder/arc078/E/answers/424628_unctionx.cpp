#include<stdio.h>
#include<string>
using namespace std;

int N;
string s="99999999999", dap="";

bool quest(string k){
	char c;
	printf("? %s\n", k.c_str()); fflush(stdout);
	scanf("\n%c", &c);
	if(c == 'Y') return 1;
	return 0;
}

int main(){
	int chk=1;
	for(int i=0; i<10; i++){
		int mi='1', mx='9', md;
		if(i) mi='0';
		while(1){
			md=(mi+mx)/2;
			s[i]=md;
			if(mi == mx) break;
			if(quest(s)) mx=md; // jarisu <= md
			else mi=md+1;
		}
		dap += md;
		if(md != '9') chk=0;
		if(chk){ // 999999
			string g="1";
			for(int j=0; j<=i; j++) g += '0';
			if(!quest(g)) break;
		}
		else{
			string g=dap;
			for(int j=0; j<g.size(); j++) if(g[j]!='9') g[j]++;
			if(quest(g)) break;
		}
	}
	printf("! %s\n", dap.c_str()); fflush(stdout);
	return 0;
}
