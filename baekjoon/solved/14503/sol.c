#include <stdio.h>
#include <stdlib.h>

#define N 50

const int DX[4] = {-1, 0, 1, 0};
const int DY[4] = {0, 1, 0, -1};

int ans;
int a[N][N];

void Dfs(int x, int y, int d) {
//	fprintf(stderr, "(%d, %d)\n", x, y);
	if (a[x][y] == 0) {
		ans++;
		a[x][y] = 2;
	}
	for (int i = 0; i < 4; i++) {
		d = (d + 3) & 3;
		int nx = x + DX[d];
		int ny = y + DY[d];
		if (a[nx][ny] == 0) {
			Dfs(nx, ny, d);
		}
	}
	int nx = x - DX[d];
	int ny = y - DY[d];
	if (a[nx][ny] == 1) {
		printf("%d\n", ans);
		exit(0);
	}
	Dfs(nx, ny, d);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int r, c, d;
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", a[i] + j);
		}
	}
	ans = 0;
	Dfs(r, c, d);
	return 0;
}
