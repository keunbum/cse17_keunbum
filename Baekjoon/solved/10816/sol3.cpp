#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (i > 0) {
			cout << ' ';
		}
		cout << (int) (upper_bound(a.begin(), a.end(), x) - lower_bound(a.begin(), a.end(), x));
	}
	cout << '\n';
	return 0;
}
