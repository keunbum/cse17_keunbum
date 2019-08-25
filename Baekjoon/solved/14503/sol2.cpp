#include <bits/stdc++.h>

using namespace std;

const int N = 50;

const int DX[4] = {-1, 0, 1, 0};
const int DY[4] = {0, 1, 0, -1};

int a[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x, y, dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	while (a[x][y] != 1) {
		if (a[x][y] == 0) {
			ans++;
			a[x][y] = 2;
		}
		bool ok = false;
		for (int i = 0; i < 4; i++) {
			dir = (dir + 3) & 3;
			int nx = x + DX[dir];
			int ny = y + DY[dir];
			if (a[nx][ny] == 0) {
				ok = true;
				x = nx;
				y = ny;
				break;
			}
		}
		if (!ok) {
			x -= DX[dir];
			y -= DY[dir];
		}
	}
	cout << ans << '\n';
	return 0;
}
