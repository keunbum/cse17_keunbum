#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6;

int a[N], b[N], p[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int k = (lower_bound(b, b + cnt, i, [&](int i, int j) { return a[i] < a[j]; }) - b);
		b[k] = i;
		cnt += (int) (k == cnt);
		p[b[k]] = k > 0 ? b[k - 1] : -1;
	}
	cout << cnt << '\n';
	function<void(int)> Print = [&](int i) {
		if (p[i] != -1) {
			Print(p[i]);
			cout << ' ';
		}
		cout << a[i];
	};
	Print(b[cnt - 1]);
	cout << '\n';
	return 0;
}
