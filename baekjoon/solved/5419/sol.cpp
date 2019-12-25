#include <bits/stdc++.h>

using namespace std;

struct Event {
	int x, y;
	int ty;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<Event> a(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a[i] = {x, y, y};
		}
		sort(a.begin(), a.end(), [&](const Event& p, const Event& q) {
			return p.y < q.y;
		});
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			a[i].y = (i > 0 && a[i].ty == a[i - 1].ty) ? a[i - 1].y : cnt++;
		}
		sort(a.begin(), a.end(), [&](const Event& p, const Event& q) {
			if (p.x != q.x) {
				return p.x > q.x;
			}
			return p.y < q.y;
		});
		vector<int> fenw(n, 0);
		auto Modify = [&](int x, int v) {
			while (x < n) {
				fenw[x] += v;
				x |= (x + 1);
			}
		};
		auto Get = [&](int x) {
			int res = 0;
			while (x >= 0) {
				res += fenw[x];
				x = (x & (x + 1)) - 1;
			}
			return res;
		};
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += Get(a[i].y);
			Modify(a[i].y, 1);
		}
		cout << ans << '\n';
	}
	return 0;
}
