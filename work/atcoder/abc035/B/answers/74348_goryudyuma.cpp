#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	int T;
	cin >> S >> T;
	int nowx = 0, nowy = 0, count = 0;
	for( auto x : S ) {
		if( x == 'L' ) {
			nowx--;
		} else if( x == 'R' ) {
			nowx++;
		} else if( x == 'U' ) {
			nowy++;
		} else if( x == 'D' ) {
			nowy--;
		} else {
			count++;;
		}
	}
	int nowl = abs( nowx ) + abs( nowy );
	if( T == 1 ) {
		cout << nowl + count << endl;
	} else {
		if( nowl <= count ) {
			cout << (count - nowl) % 2 << endl;
		} else {
			cout << nowl - count << endl;
		}
	}
}