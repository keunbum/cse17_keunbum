#include <bits/stdc++.h>

using namespace std;

string a[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = ans; i + k < n && j + k < m; k++) {
				if (a[i][j] == a[i + k][j] && a[i][j] == a[i][j + k] && a[i][j] == a[i + k][j + k]) {
					ans = k + 1;
				}
			}
		}
	}
	cout << ans * ans << '\n';
	return 0;
}
