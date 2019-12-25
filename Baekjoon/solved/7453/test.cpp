#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 4000;
	cout << N << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			if (j > 0) cout << ' ';
			cout << i - N / 2;
		}
		cout << '\n';
	}
	return 0;
}
