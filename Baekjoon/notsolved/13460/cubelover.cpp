#include <cstdio>

int n, m;
char a[11][11];

int px[4] = { -1, 1, 0, 0 };
int py[4] = { 0, 0, -1, 1 };

int g(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#';
}

int f(int Rx, int Ry, int Bx, int By, int z, int w) {
	if (z == 10) return -1;
	int i, j, k = -1;
	for (i = 0; i < 4; i++) if (i != w && i != (w ^ 1)){
		int rx = Rx, ry = Ry, bx = Bx, by = By;
		while (
			a[rx][ry] != 'O' && a[bx][by] != 'O' &&
			(!g(rx + px[i], ry + py[i]) && (rx + px[i] != bx || ry + py[i] != by) ||
			!g(bx + px[i], by + py[i]) && (bx + px[i] != rx || by + py[i] != ry))) {
			if (rx + px[i] == bx && ry + py[i] == by) {
				rx += px[i];
				ry += py[i];
				bx += px[i];
				by += py[i];
			}
			else {
				if (!g(rx + px[i], ry + py[i])) {
					rx += px[i];
					ry += py[i];
				}
				if (!g(bx + px[i], by + py[i]) && (bx + px[i] != rx || by + py[i] != ry)) {
					bx += px[i];
					by += py[i];
				}
			}
		}
		if (a[bx][by] == 'O') continue;
		if (a[rx][ry] == 'O') {
			while (a[bx][by] != 'O' && !g(bx + px[i], by + py[i])) {
				bx += px[i];
				by += py[i];
			}
			if (a[bx][by] != 'O') return z + 1;
			continue;
		}
		j = f(rx, ry, bx, by, z + 1, i);
		if (j != -1 && (k == -1 || k > j)) k = j;
	}
	return k;
}

int main() {
	int i, j, Rx, Ry, Bx, By;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
		for (j = 0; j < m; j++) {
			if (a[i][j] == 'R') {
				Rx = i;
				Ry = j;
			}
			if (a[i][j] == 'B') {
				Bx = i;
				By = j;
			}
		}
	}
	printf("%d", f(Rx, Ry, Bx, By, 0, -1));
}
