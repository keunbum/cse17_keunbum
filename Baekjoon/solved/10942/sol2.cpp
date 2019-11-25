#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

int a[N];
bool dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int s = 0, e = s + i - 1; e < n; s++, e++) {
			if (a[s] == a[e]) {
				dp[s][e] = (e - s <= 2) ? true : dp[s + 1][e - 1];
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << dp[x][y] << '\n';
	}
	return 0;
}
