#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

int q[N + 1], deg[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = 1e9;
	int n;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		int u = i * 3;
		if (u <= n) {
			g[i].push_back(u);
			deg[u]++;
		}
		u = i << 1;
		if (u <= n) {
			g[i].push_back(u);
			deg[u]++;
		}
		u = i + 1;
		if (u <= n) {
			g[i].push_back(u);
			deg[u]++;
		}
	}
	q[0] = 1;
	int b = 0, e = 1;
	vector<int> dp(n + 1, INF);
	dp[1] = 0;
	while (b < e) {
		int v = q[b];
		for (int u : g[v]) {
			dp[u] = min(dp[u], dp[v] + 1);
			if (--deg[u] == 0) {
				q[e++] = u;
			}
		}
		b++;
	}
	cout << dp[n] << '\n';
	while (n > 1) {
		cout << n << ' '; 
		int mn = INF;
		int mi = -1;
		int u;
		if (n % 3 == 0) {
			u = n / 3;
			if (mn > dp[u]) {
				mn = dp[u];
				mi = u;
			}
		}
		if ((n & 1) == 0) {
			u = n >> 1;
			if (mn > dp[u]) {
				mn = dp[u];
				mi = u;
			}
		}
		u = n - 1;
		if (mn > dp[u]) {
			mn = dp[u];
			mi = u;
		}
		n = mi;
	}
	cout << 1 << '\n';
//	cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
	return 0;
}
