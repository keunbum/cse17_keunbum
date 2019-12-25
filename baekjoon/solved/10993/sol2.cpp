#include <bits/stdc++.h>

using namespace std;

const int H = (1 << 10);
const int W = (1 << 11);

char a[H][W];

void Do(int n, int sx, int sy) {
//	cerr << n << ' ' << sx << ' ' << sy << '\n';
	if (n == 1) {
		a[sx][sy] = '*';
		return;
	}
	bool odd = (bool) (n & 1);
	int vx, vy;
	vx = vy = odd ? -1 : 1;
	int w = (1 << (n + 1)) - 3;
	int h = (1 << n) - 1;
	int cx = sx;
	int cy = sy;
	int i;
	for (i = -(w / 2); i < 0; i++, cx += vx, cy += vy) {
		a[cx][cy] = '*';
	}
	vx *= -1;
	for ( ; i < (w / 2); i++, cx += vx, cy += vy) {
		a[cx][cy] = '*';
	}
	vy *= -1;
	for (i = 0; i < w; i++, cy += vy) {
		a[cx][cy] = '*';
	}
	int nx = sx + (h / 2) * (odd ? -1 : 1);
	int ny = sy + (w / 2 - 1) * (odd ? -1 : 1);
	ny += (w / 4) * (odd ? -1 : 1);
	Do(n - 1, nx, ny);
}

void Solve(int n) {
	bool odd = (bool) (n & 1);
	int h = (1 << n) - 1;
	int w = (1 << (n + 1)) - 3;
	int sx, sy;
	if (odd) {
		sx = h - 1;
		sy = w - 1;
	} else {
		sx = sy = 0;
	}
	Do(n, sx, sy);
	// output
	int iy = w - 1;
	if (odd) {
		iy >>= 1;
	}
	for (int i = 0; i < h; i++) {
		a[i][iy + i * (odd ? 1 : -1) + 1] = 0;
		cout << a[i] << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	memset(a, ' ', sizeof(a));
	Solve(n);
	return 0;
}
