#include <bits/stdc++.h>

using namespace std;

const int MAX = 333335;

char s[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	if (s[0] == '0') {
		cout << "0" << '\n';
		return 0;
	}
	for (int i = 0; s[i]; i++) {
		int x = s[i] - '0';
		char buf[4];
		buf[3] = 0;
		for (int p = 2; ~p; p--) {
			buf[p] = (x & 1) + '0';
			x >>= 1;
		}
		int p = 0;
		if (i == 0) {
			while (buf[p] == '0') p++;
		}
		cout << (buf + p);
	}
	cout << '\n';
	return 0;
}
