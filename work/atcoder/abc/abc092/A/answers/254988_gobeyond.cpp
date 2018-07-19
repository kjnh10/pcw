#include <iostream>
using namespace std;

int main(){
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if(A>B) A=B;
	if(C>D) C=D;
	cout << A+C << endl;
}