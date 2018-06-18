#include <bits/stdc++.h>
using namespace std;

int main(void){
	int sx,sy,tx,ty;
	cin >> sx >> sy >> tx >> ty;
	const int dx=tx-sx,dy=ty-sy;

	// Path 1
	cout << string(dy,'U') << string(dx,'R');
	
	// Path 2
	cout << string(dy,'D') << string(dx,'L');
		
	// Path 3
	cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';
	
	// Path 4
	cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U';
		
	// EndLine
	cout << endl;
	return 0;
}
