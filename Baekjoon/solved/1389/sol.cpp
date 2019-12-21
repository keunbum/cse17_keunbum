#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int g[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int inf = (int) 1e9;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = inf;
		}
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x][y] = 1;
		g[y][x] = 1;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int mi = 0, mn = inf;
	for (int i = 0; i < n; i++) {
		int foo = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				foo += g[i][j];
			}
		}
		if (foo < mn) {
			mn = foo;
			mi = i;
		}
	}
	cout << mi + 1 << '\n';
	return 0;
}
