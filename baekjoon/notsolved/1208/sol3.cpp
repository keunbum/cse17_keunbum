#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m = n >> 1;
	vector<int> b(1 << m);
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < m; j++) {
			b[i] += a[j] * ((i >> j) & 1);
		}
	}
	sort(b.begin(), b.end());
	int l = (n + 1) / 2;
	long long ans = 0;
	for (int i = 0; i < (1 << l); i++) {
		int sum = 0;
		for (int j = 0; j < l; j++) {
			sum += a[m + j] * ((i >> j) & 1);
		}
		ans += (int) (upper_bound(b.begin(), b.end(), s - sum) - lower_bound(b.begin(), b.end(), s - sum));
	}
	cout << ans << '\n';
	return 0;
}
