#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

#include <cstring>

using namespace std;

#define FOR(var,start,end) for(int var=start; var<end; var++)
#define REP(var,cnt) FOR(var,0,cnt)

bool DP[2][17000];

int main(void) {
	
	string S;
	cin >> S;
	
	int X, Y;
	cin >> X >> Y;
	
	
	vector<int> list[2]; //tate, yoko
	int isYoko = 1;
	int accum = 0;
	
	for( char& c : S ) {
		if ( c == 'F' ) {
			accum ++;
		} else {
			list[ isYoko ].push_back( accum );
			accum = 0;
			isYoko = (isYoko+1)%2;
		}
	}
	list[ isYoko ].push_back( accum );
	
	const int SAB = 8500;
	
	DP[0][0 + SAB] = true;
	DP[1][0 + SAB] = true;
	
	REP(bb, 2) {
		
		for (int ppos=0; ppos < list[bb].size(); ppos++) {
		//for ( int x : list[bb] ) {
		
			int x = list[bb][ppos];
			
			bool temp[17000];
			REP(i,17000) { temp[i] = false; }
			
			REP(i, 17000) {
				if ( DP[bb][i] == true ) {
				//	cout << bb << " " << i << " is true " << x << endl;
					if ( bb == 1 && ppos == 0 ) {
						temp[i + x] = true;
					} else {
						temp[i - x] = true;
						temp[i + x] = true;
					}
				}
			}
			
			memcpy(DP[bb], temp, sizeof(bool)*17000);
			
			/*
			cout << bb << " " << x << " ";
			for(int ps=SAB-10; ps<SAB+10; ps++) {
				if ( ps ==SAB ) { cout<<"*"; }
				cout << DP[bb][ps] ? '+' : '.';
			}
			cout << endl;
			*/
		}
	}
	
	
	if ( DP[0][Y+SAB] && DP[1][X+SAB] ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
