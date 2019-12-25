#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> cnt(d + 1, 0);
	int cur = 0;
	for (int i = 0; i < k; i++) {
		if (cnt[a[i]]++ == 0) {
			cur++;
		}
	}
	int b = 0, e = k;
	int ans = cur + !cnt[c];
	while (b < n) {
		if (--cnt[a[b]] == 0) {
			cur--;
		}
		if (e >= n) {
			e = 0;
		}
		if (cnt[a[e]]++ == 0) {
			cur++;
		}
		b++; e++;
		ans = max(ans, cur + !cnt[c]);
	}
	cout << ans << '\n';
	return 0;
}
