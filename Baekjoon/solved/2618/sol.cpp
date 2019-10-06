#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int dp[N][N];
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n + 1; i++) {
		cin >> a[i].first >> a[i].second;
	}
	auto Dis = [&](pair<int, int>& p, pair<int, int>& q) {
		return abs(p.first - q.first) + abs(p.second - q.second);
	};
	memset(dp, -1, sizeof(dp));
	a[0] = {1, 1};
	a[1] = {m, m};
	function<int(int, int)> Dfs = [&](int x, int y) {
		if (x == n + 1 || y == n + 1) {
			return 0;
		}
		if (dp[x][y] >= 0) {
			return dp[x][y];
		}
		int z = max(x, y) + 1;
		return dp[x][y] = min(Dfs(z, y) + Dis(a[x], a[z]), Dfs(x, z) + Dis(a[y], a[z]));
	};
	cout << Dfs(0, 1) << '\n';
	int x = 0;
	int y = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (dp[i][y] + Dis(a[x], a[i]) < dp[x][i] + Dis(a[y], a[i])) {
			cout << 1 << '\n';
			x = i;
		} else {
			cout << 2 << '\n';
			y = i;
		}
	}
	return 0;
}
