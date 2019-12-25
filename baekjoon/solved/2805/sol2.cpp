#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int low = 0;
	int high = (int) 1e9;
	while (low < high) {
		int mid = (low + high + 1) / 2;
//		cerr << low << ' ' << mid << ' ' << high << '\n';
		long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i] - min(a[i], mid);
		}
		if (sum >= m) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	cout << low << '\n';
	return 0;
}
