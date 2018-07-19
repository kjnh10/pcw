#include <bits/stdc++.h>
using namespace std;

using ld = long double;
const ld eps = 1e-8, pi = acos(-1.0);

bool eq(ld a, ld b) {
	return abs(a - b) < eps;
}

using Point = complex<ld>;
class Line {
public:
	Point a, b;
};
ld dot(Point a, Point b) {
	return real(conj(a) * b);
}

ld cross(Point a, Point b) {
	return imag(conj(a) * b);
}

int ccw(Point a, Point b, Point c) {
	b -= a, c -= a;
	if (cross(b, c) > eps) return 1;	// a,b,cが反時計周り
	if (cross(b, c) < -eps) return -1;	// a,b,cが時計回り
	if (dot(b, c) < 0) return 2;		// c,a,bの順で直線
	if (norm(b) < norm(c)) return -2;	// a,b,cの順に直線
	return 0;							// a,c,bの順に直線
}

bool isis_ll(Line l, Line m) {
	return abs(cross(l.b - l.a, m.b - m.a)) > eps;
}

bool isis_ls(Line l, Line s) {
	return (cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) < eps);
}

int main()
{
	int N;
	ld Ax, Ay, Bx, By;
	cin >> Ax >> Ay >> Bx >> By >> N;
	Point A(Ax, Ay), B(Bx, By);
	vector<ld> X(N), Y(N);
	vector<Point> p(N);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		p[i] = Point(X[i], Y[i]);
	}
	for (int i = 0; i < N; i++) {
		if (ccw(A, B, p[i]) != ccw(A, B, p[(i + 1) % N])
			&& isis_ls((Line) { p[i], p[(i + 1) % N] }, (Line) { A, B })) {
			cnt++;
		}
	}
	cout << 1 + cnt / 2 << endl;
	return 0;
}
