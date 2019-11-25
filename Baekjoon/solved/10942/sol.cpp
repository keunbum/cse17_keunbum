#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	memset(dp, -1, sizeof(dp));
	function<int(int, int)> F = [&](int x, int y) {
		if (~dp[x][y]) {
			return dp[x][y];
		}
		if (a[x] == a[y]) {
			if (y - x <= 2) {
				return dp[x][y] = 1;
			}
			return dp[x][y] = F(x + 1, y - 1);
		}
		return dp[x][y] = 0;
	};
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		if (x > y) {
			swap(x, y);
		}
		cout << F(x, y) << '\n';
	}
	return 0;
}
