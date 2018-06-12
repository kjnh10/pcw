#include <cstdio>
using namespace std;

int main(){
	int n,r = 0,b = 0;
	scanf("%d",&n);
	getchar();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			char c = getchar();
			if(c == 'R') r++;
			else if(c == 'B') b++;
		}
		getchar();
	}
	if(r > b) printf("TAKAHASHI\n");
	else if(r == b) printf("DRAW\n");
	else printf("AOKI\n");
	return 0;
}