#include <bits/stdc++.h>

using namespace std;

const int MD = (int) 1e9;

int dp[101][10][10][10];

// dp[a][b][c][d]: 길이가 a이고, x = (b <= x <= c) 수들을 포함하면서 마지막 자리가 d인 수의 개수

inline int Add(int a, int b) {
	a += b;
	if (a >= MD) a -= MD;
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i < 10; i++) {
		dp[1][i][i][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j + 1; k < 10; k++) {
				dp[i][j][k][j] = Add(dp[i - 1][j][k][j + 1], dp[i - 1][j + 1][k][j + 1]);
				dp[i][j][k][k] = Add(dp[i - 1][j][k][k - 1], dp[i - 1][j][k - 1][k - 1]);
				for (int l = j + 1; l < k; l++) {
					dp[i][j][k][l] = Add(dp[i - 1][j][k][l - 1], dp[i - 1][j][k][l + 1]);
				}
			}
		}
	}
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = Add(ans, dp[n][0][9][i]);
	}
	cout << ans << '\n';
	return 0;
}
