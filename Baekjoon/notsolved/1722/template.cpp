#include <bits/stdc++.h>

using namespace std;

const int N = (int) 4e5;
const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

bool was[N];
int dist[N];
int q[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> fact(9);
	fact[0] = 1;
	for (int i = 1; i < 9; i++) {
		fact[i] = fact[i - 1] * i;
	}
//	debug(fact);
	vector<int> a(9);
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
//	debug(a);
	auto F = [&](vector<int>& a, int n) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					cnt++;
				}
			}
			res += cnt * fact[n - 1 - i];
		}
		return res;
	};
	auto Inv = [&](int x, int n) {
		vector<bool> chk(10);
		vector<int> res(n);
		for (int i = 0; i < n; i++) {
			int t = x / fact[n - 1 - i];
			x = x % fact[n - 1 - i];
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (!chk[j]) {
					if (cnt == t) {
						res[i] = j;
						chk[j] = true;
						break;
					}
					cnt++;
				}
			}
		}
		return res;
	};
	int st = F(a, 9);
//	debug(st);
	for (int i = 0; i < 9; i++) {
		a[i] = (i + 1) % 9;
	}
//	debug(a);
	int en = F(a, 9);
	int b = 0, e = 1;
	q[0] = st;
	dist[st] = 0;
	was[st] = true;
	while (b < e) {
		auto v = Inv(q[b], 9);
//		debug(v);
		auto u(v);
		int x, y, A;
		for (int i = 0; i < 9; i++) {
			if (v[i] == 0) {
				A = i;
				x = i / 3;
				y = i % 3;
			}
		}
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + DX[dir];
			int ny = y + DY[dir];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				int B = 3 * nx + ny;
				swap(u[A], u[B]);
				int uu = F(u, 9);
				swap(u[A], u[B]);
				if (!was[uu]) {
					q[e] = uu;
					was[uu] = true;
					dist[uu] = dist[q[b]] + 1;
					++e;
				}
			}
		}
		++b;
	}
	cout << (was[en] ? dist[en] : -1) << '\n';
	return 0;
}
