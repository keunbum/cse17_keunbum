#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 100;
	const int M = 10000000;
	cout << N << ' ' << M << '\n';
	for (int i = 1; i <= N; i++) {
		if (i > 1) {
			cout << ' ';
		}
		cout << (i == 1 ? M : 1);
	}
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		if (i > 1) {
			cout << ' ';
		}
		cout << i;
	}
	cout << '\n';
	return 0;
}
