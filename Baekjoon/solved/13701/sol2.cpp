#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 22;

char s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x;
	while (cin >> x) {
		int y = x >> 3;
		int z = x & 7;
		if ((s[y] & (1 << z)) == 0) {
			cout << x << ' ';
			s[y] |= (1 << z);
		}
	}
	cout << '\n';
	return 0;
}
