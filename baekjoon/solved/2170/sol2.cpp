#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

pair<int, int> a[N + N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, 1};
		a[i + n] = {y, -1};
	}
	sort(a, a + n + n);
	int top = 0;
	int ans = 0;
	for (int i = 0; i < n + n; i++) {
		if (top > 0) {
			ans += a[i].first - a[i - 1].first;
		}
		top += a[i].second;
	}
	cout << ans << '\n';
	return 0;
}
