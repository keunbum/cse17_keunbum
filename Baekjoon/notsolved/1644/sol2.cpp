#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<bool> p(n + 1, true);
	vector<int> a;
	a.push_back(0);
	for (int i = 2; i <= n; i++) {
		if (p[i]) {
			a.push_back(i);
			for (int j = i + i; j <= n; j += i) {
				p[j] = false;
			}
		}
	}
	int m = (int) a.size();
	for (int i = 1; i < m; i++) {
		a[i] += a[i - 1];
	}
	int e = 0;
	long long ans = 0LL;
	for (int i = 1; i < m; i++) {
		while (a[i] - a[e] > n) {
			e++;
		}
		if (a[i] - a[e] == n) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
