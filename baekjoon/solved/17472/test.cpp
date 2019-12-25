#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 100;
	const int M = 100;
	cout << N << ' ' << M << '\n';
	mt19937 rng(58);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (j > 0) {
				cout << ' ';
			}
			cout << rng() % 2;
		}
		cout << '\n';
	}
	return 0;
}
