#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e6;

int d[MAX]; // save the index

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, w;
	cin >> n >> w;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(n); // save the value
	int beg = 0, end = 0;
	for (int i = 0; i <= n; i++) {
		if (i >= w) {
			b[i - w] = a[d[beg]];
		}
		while (beg < end && a[d[end - 1]] > a[i]) {
			end--;
		}
		d[end++] = i;
		if (d[beg] == i - w) {
			beg++;
		}
	}
	beg = 0, end = 0;
	long long ans1 = 0;
	int ans2 = 0;
	int pre = 0;
	int oki = -1;
	for (int i = 0; i < n; i++) {
		while (beg < end && b[d[end - 1]] < b[i]) {
			end--;
		}
		d[end++] = i; // push
		if (d[beg] == i - w) {
			beg++;
		} // pop
		int cur = b[d[beg]]; // determine
		ans1 += a[i] - cur;
		if (cur != pre || oki < i) {
			ans2++;
			pre = cur;
			oki = i + w - 1;
		}
	}
//	cerr << (float) clock() / CLOCKS_PER_SEC << " s" << '\n';
	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
