#include <bits/stdc++.h>

using namespace std;

bool chka[10][10], chkb[10][10], chkc[10][10];
int a[9][9];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int x;
			cin >> x;
			a[i][j] = x;
			if (x > 0) {
				chka[i][x] = chkb[j][x] = chkc[(i / 3) * 3 + j / 3][x] = true;
			}
		}
	}
	function<void(int)> Dfs = [&](int d) {
		if (d == 81) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					if (j > 0) {
						cout << ' ';
					}
					cout << a[i][j];
				}
				cout << '\n';
			}
			exit(0);
		}
		int x = d / 9;
		int y = d % 9;
		if (a[x][y] > 0) {
			Dfs(d + 1);
			return;
		}
		int z = (x / 3) * 3 + y / 3;
		for (int i = 1; i <= 9; i++) {
			if (chka[x][i] || chkb[y][i] || chkc[z][i]) {
				continue;
			}
			chka[x][i] = chkb[y][i] = chkc[z][i] = true;
			a[x][y] = i;
			Dfs(d + 1);
			chka[x][i] = chkb[y][i] = chkc[z][i] = false;
		}
		a[x][y] = 0;
	};
	Dfs(0);
	assert(0);
	return 0;
}
