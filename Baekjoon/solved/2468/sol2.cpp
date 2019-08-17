#include <bits/stdc++.h>

using namespace std;

const int N = 123;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int a[N][N];
bool was[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int h = 0; h <= 100; h++) {
		fill_n(was[0], N * N, false);
		function<void(int, int)> Dfs = [&](int x, int y) {
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + DX[dir];
				int ny = y + DY[dir];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] > h && !was[nx][ny]) {
					was[nx][ny] = true;
					Dfs(nx, ny);
				}
			}
		};
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!was[i][j] && a[i][j] > h) {
					was[i][j] = true;
					cnt++;
					Dfs(i, j);
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
	return 0;
}
