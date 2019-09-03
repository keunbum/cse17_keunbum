#include <bits/stdc++.h>

using namespace std;

const int N = 100;

struct Rec {
	int xa, xb, ya, yb;
};

int x[2 * N], y[2 * N];
Rec a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1;
		cin >> x1 >> y1;
		int x2 = x1 + 10;
		int y2 = y1 + 10;
		x[i] = x1; x[i + n] = x2;
		y[i] = y1; y[i + n] = y2;
		a[i] = {x1, x2, y1, y2};
	}
	sort(x, x + 2 * n);
	sort(y, y + 2 * n);
	int ans = 0;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			for (int k = 0; k < n; k++) {
				if (x[i] >= a[k].xa && x[i + 1] <= a[k].xb && y[j] >= a[k].ya && y[j + 1] <= a[k].yb) {
					ans += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
					break;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
