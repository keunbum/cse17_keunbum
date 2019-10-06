#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int dp[N][N];
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int A[7] = {9, 11, 0, 2, 4, 5, 7};
	auto T = [&](const char* s) {
		return A[s[0] - 'A'] + 12 * (s[1] - '0') + (int) (s[2] == '#');
	};
	char fir[5], sec[5];
	cin >> fir >> sec;
	a[0] = T(fir); a[1] = T(sec);
	int n;
	cin >> n;
	for (int i = 2; i <= n + 1; i++) {
		char foo[5];
		cin >> foo;
		a[i] = T(foo);
	}
	memset(dp, -1, sizeof(dp));
	function<int(int, int)> Dfs = [&](int x, int y) {
		if (x == n + 1 || y == n + 1) {
			return 0;
		}
		if (dp[x][y] >= 0) {
			return dp[x][y];
		}
		int z = max(x, y) + 1;
		return dp[x][y] = min(Dfs(z, y) + abs(a[x] - a[z]), Dfs(x, z) + abs(a[y] - a[z]));
	};
	cout << Dfs(0, 1) << '\n';
	int x = 0;
	int y = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (i > 2) {
			cout << ' ';
		}
		if (dp[i][y] + abs(a[x] - a[i]) < dp[x][i] + abs(a[y] - a[i])) {
			cout << 1;
			x = i;
		} else {
			cout << 2;
			y = i;
		}
	}
	cout << '\n';
	return 0;
}
