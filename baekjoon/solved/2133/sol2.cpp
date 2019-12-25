#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 31;
	int f[3][N][8];
	fill_n(f[0][0], 3 * N * 8, -1);
	int n;
	cin >> n;
	function<int(int, int, int)> Dfs = [&](int x, int y, int bits) {
//		cerr << x << ' ' << y << ' ' << bits << '\n';
		if (y == n) {
			return 1;
		}
		if (x == 3) {
			return Dfs(0, y + 1, bits);
		}
		if (f[x][y][bits] >= 0) {
			return f[x][y][bits];
		}
		if (bits & (1 << x)) {
			return Dfs(x + 1, y, bits ^ (1 << x));
		}
		int res = 0;
		if (y < n - 1) {
			res += Dfs(x + 1, y, bits | (1 << x));
		}
		if (x < 2 && (bits & (3 * (1 << x))) == 0) {
			res += Dfs(x + 2, y, bits);
		}
		return f[x][y][bits] = res;
	};
	cout << Dfs(0, 0, 0) << '\n';
	return 0;
}
