#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	int N;
	cin >> N;
	if (!(N % 400)) cout << "YES" << endl;
	else if (!(N % 100))  cout << "NO" << endl;
	else if (!(N % 4))  cout << "YES" << endl;
	else  cout << "NO" << endl;
}