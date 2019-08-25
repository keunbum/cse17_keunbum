#include <iostream>
#include <functional>

using namespace std;

const int N = 123;

int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, t, k;
	cin >> n >> m >> t >> k;
	n *= 2;
	m *= 2;
	k *= 2;
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		x *= 2; y *= 2;
		a[i] = x; b[i] = y;
	}
	int ans = 0;
	int cx = -1;
	int cy = -1;
	function<void(int, int)> Cnt = [&](int x, int y) {
		if (x & 1) {
			Cnt(x + 1, y);
		}
		if (y & 1) {
			Cnt(x, y + 1);
		}
		int cnt = 0;
		for (int i = 0; i < t; i++) {
			if (abs(x - a[i]) + abs(y - b[i]) <= k / 2) {
				cnt++;
			}
		}
		if (cnt > ans) {
			ans = cnt;
			cx = x;
			cy = y;
		}
	};
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			int dd = (a[j] - a[i]) + (b[j] - b[i]);
			int tx = a[i] + dd / 2;
			int ty = b[i] + dd / 2;
			if (dd >= 0) {
				Cnt(tx - k / 2, ty);
				Cnt(tx, ty - k / 2);
			}
			if (dd <= 0) {
				Cnt(tx + k / 2, ty);
				Cnt(tx, ty + k / 2);
			}
		}
	}
	if (cx < 0) {
		cx = 0;
	}
	if (cx > n) {
		cx = n;
	}
	if (cy < 0) {
		cy = 0;
	}
	if (cy > m) {
		cy = m;
	}
	cout << cx / 2 << ' ' << cy / 2 << '\n';
	cout << ans << '\n';
	return 0;	
}
