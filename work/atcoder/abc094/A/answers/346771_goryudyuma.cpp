#include<bits/stdc++.h>
/*
*/

using namespace std;

typedef pair<long long int, vector<long long int>> PLVL;

int main(){
	long long int A, B, X;
	cin >> A >> B >> X;
	if( A <= X && X <= A + B ){
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}
}

