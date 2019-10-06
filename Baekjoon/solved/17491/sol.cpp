#include <bits/stdc++.h>

using namespace std;

const int N = 17;

int x[N], y[N];
int adj[N][N];
int dp[N][1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = (int) 2e9;
	int n;
	cin >> n;
	n++;
	x[0] = y[0] = 0;
	for (int i = 1; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				adj[i][j] = INF;
				continue;
			}
			adj[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}
	fill_n(dp[0], N * (1 << N), INF);
	dp[0][1] = 0;
	for (int t = 1; t < (1 << n); t++) {
		for (int i = 0; i < n; i++) {
			if (dp[i][t] == INF) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if ((t | (1 << j)) == t) {
					continue;
				}
				dp[j][t | (1 << j)] = min(dp[j][t | (1 << j)], dp[i][t] + adj[j][i]);
			}
		}
	}
	int ans = INF;
	for (int i = 1; i < n; i++) {
		ans = min(ans, dp[i][(1 << n) - 1] + adj[0][i]);
	}
	cout << ans << '\n';
	return 0;
}
