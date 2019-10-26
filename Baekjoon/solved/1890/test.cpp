#include <bits/stdc++.h>

using namespace std;

mt19937 rng(14523462346461234L);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int N = 100;
	cout << N << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j > 0) {
				cout << ' ' ;
			}
			cout << rng() % 10;
		}
		cout << '\n';
	}
	
	return 0;
}
