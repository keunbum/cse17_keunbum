#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector<int> dpa(n + 1);
	for (int i = 1; i <= n; i++) {
		dpa[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				dpa[i] = max(dpa[i], dpa[j] + 1);
			}
		}
	}
	vector<int> dpb(n + 1);
	int ans = 1;
	for (int i = n; i >= 1; i--) {
		dpb[i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j]) {
				dpb[i] = max(dpb[i], dpb[j] + 1);
			}
		}
		ans = max(ans, dpa[i] + dpb[i] - 1);
	}
	cout << ans << '\n';
	return 0;
}
