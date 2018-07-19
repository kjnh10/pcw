#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,r,res = 0,last = -1;
	string s;
	cin >> n >> r >> s;
	for(int i = 0;i < n;i++) if(s[i] == '.') last = i;
	if(last == -1){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0;i < n;i++){
		if(i >= last - r + 1){
			res++;
			break;
		}
		if(s[i] == '.'){
			for(int j = 0;j < r;j++) s[i + j] = 'o';
			res++;
		}
		res++;
	}
	cout << res << endl;
	return 0;
}