#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e7;

int cnt[N + N + 10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x + N]++;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (i > 0) {
			cout << ' ';
		}
		cout << cnt[x + N];
	}
	cout << '\n';
	return 0;
}
