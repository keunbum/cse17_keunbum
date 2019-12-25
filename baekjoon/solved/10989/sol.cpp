#include <bits/stdc++.h>

using namespace std;

const int MAXV = (int) 1e4;

int a[MAXV + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		a[t]++;
	}
	for (int i = 1; i <= MAXV; i++) {
		int t = a[i];
		while (t--) {
			cout << i << '\n';
		}
	}
	return 0;
}
