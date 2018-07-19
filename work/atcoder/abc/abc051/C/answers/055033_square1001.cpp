#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int sx, sy, tx, ty;
int main() {
	cin >> sx >> sy >> tx >> ty;
	int ex = tx - sx, ey = ty - sy;
	for (int i = 0; i < ex; i++) cout << 'R';
	for (int i = 0; i < ey; i++) cout << 'U';
	for (int i = 0; i < ex; i++) cout << 'L';
	for (int i = 0; i < ey; i++) cout << 'D';
	cout << 'D';
	for (int i = 0; i < ex + 1; i++) cout << 'R';
	for (int i = 0; i < ey + 1; i++) cout << 'U';
	cout << 'L';
	cout << 'U';
	for (int i = 0; i < ex + 1; i++) cout << 'L';
	for (int i = 0; i < ey + 1; i++) cout << 'D';
	cout << 'R';
	cout << endl;
	return 0;
}