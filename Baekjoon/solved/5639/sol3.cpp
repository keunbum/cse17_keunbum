#include <bits/stdc++.h>

using namespace std;

int a[12345];

void Print(int b, int e) {
	int low = b + 1;
	int high = e;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (a[mid] < a[b]) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}
	if (b + 1 < low) Print(b + 1, low);
	if (low < e) Print(low, e);
	cout << a[b] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	while (cin >> a[n]) n++;
	Print(0, n);
	return 0;
}
