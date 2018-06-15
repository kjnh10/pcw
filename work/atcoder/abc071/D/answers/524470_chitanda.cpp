#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

char s[2][60];
int n;
int f[60][3][3];

int main(){
	scanf("%d", &n);
	scanf("%s", s[0] + 1);
	scanf("%s", s[1] + 1);
	int bg;
	if(s[0][1] == s[1][1]){
		f[1][0][0] = f[1][1][1] = f[1][2][2] = 1;
		bg = 1;
	}else{
		f[2][0][1] = f[2][1][0] = f[2][0][2] = f[2][2][0]	= f[2][1][2] = f[2][2][1] = 1;
		bg = 2;
	}
	for(int i = bg + 1; i <= n;){
		if(s[0][i] == s[1][i]){
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 3; ++k)
					for(int l = 0; l < 3; ++l)
						if(l != j && l != k){
							f[i][l][l] = (f[i][l][l] + f[i - 1][j][k]) % M;
						}
			++i;
		}else{
			for(int j = 0; j < 3; ++j)
				for(int k = 0; k < 3; ++k)
					for(int l = 0; l < 3; ++l)
						for(int p = 0; p < 3; ++p)
							if(l != j && k != p && l != p){
								f[i + 1][l][p] = (f[i + 1][l][p] + f[i - 1][j][k]) % M;
							}
			i += 2;
		}
	}
	int res = 0;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			res = (res + f[n][i][j]) % M;
	printf("%d\n", res);
				 
			

	return 0;
}
