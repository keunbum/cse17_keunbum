#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e4;

const int PO10[4] = {1000, 100, 10, 1};

int q[N], was[N], d[N];
bool prime[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill_n(prime, N, true);
	for (int i = 2; i < N; i++) {
		if (!prime[i]) {
			continue;
		}
		for (int j = i * 2; j < N; j += i) {
			prime[j] = false;
		}
	}
	int tt;
	cin >> tt;
	for (int qq = 1; qq <= tt; qq++) {
		int x, y;
		cin >> x >> y;
		int b = 0, e = 1;
		q[0] = x;
		was[x] = qq;
		d[x] = 0;
		while (b < e) {
			int c = q[b++];
			int v[4];
			v[0] = c / 1000; v[1] = (c / 100) % 10; v[2] = (c / 10) % 10; v[3] = c % 10;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0) {
						continue;
					}
					int t = c + (j - v[i]) * PO10[i];
					if (was[t] != qq && prime[t]) {
						was[t] = qq;
						d[t] = d[c] + 1;
						q[e++] = t;
					}
				}
			}
		}
		cout << d[y] << '\n';
	}
	return 0;
}
