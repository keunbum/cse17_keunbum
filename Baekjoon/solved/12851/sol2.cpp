#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5;

int a[N + 1], q[N + 1], ans[N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int st, en;
	cin >> st >> en;
	int b = 0, e = 0;
	a[st] = 1;
	q[e++] = st;
	ans[st] = 1;
	while (b < e) {
		int v = q[b++];
		if (v == en) {
			break;
		}
		auto F = [&](int u) {
			if (u < 0 || u > N) {
				return;
			}
			if (a[u] == 0) {
				a[u] = a[v] + 1;
				q[e++] = u;
			}
			if (a[u] == a[v] + 1) {
				ans[u] += ans[v];
			}
		};
		F(v - 1);
		F(v + 1);
		F(v + v);
	}
	cout << a[en] - 1 << '\n' << ans[en] << '\n';
	return 0;
}
