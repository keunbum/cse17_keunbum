#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int X[20], Y[20];
int dp[1 << 16][16];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;

	cin >> N;
	for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

	for(int i = 1; i < (1 << N); i++) for(int j = 0; j < N; j++) if(i & (1 << j)) {
		if(i == (1 << j)) dp[i][j] = X[j] + Y[j];
		else {
			dp[i][j] = INF;
			for(int k = 0; k < N; k++) if(k != j && (i & (1 << k)))
				dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + abs(X[j] - X[k]) + abs(Y[j] - Y[k]));
		}
		//printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	}

	int ans = INF;
	for(int i = 0; i < N; i++) ans = min(ans, dp[(1 << N) - 1][i] + X[i] + Y[i]);
	cout << ans;
	return 0;
}
