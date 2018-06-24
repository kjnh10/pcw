#include <bits/stdc++.h>
using namespace std;

int main() {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int dx = tx - sx;
	int dy = ty - sy;

	for (int i = 0; i < dy; i++) putchar('U');
	for (int i = 0; i < dx; i++) putchar('R');

	for (int i = 0; i < dy; i++) putchar('D');
	for (int i = 0; i < dx; i++) putchar('L');

	putchar('L');
	for (int i = 0; i < dy; i++) putchar('U');
	putchar('U');
	for (int i = 0; i < dx; i++) putchar('R');
	putchar('R');
	putchar('D');

	putchar('R');
	for (int i = 0; i < dy; i++) putchar('D');
	putchar('D');
	for (int i = 0; i < dx; i++) putchar('L');
	putchar('L');
	putchar('U');
}