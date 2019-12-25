#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	const int N = 20;
	const int MAX = 20;
	cout << N << '\n' << N << '\n';
	for(int i = 0; i < MAX; i++) {
		cout << (rand() % N + 1) << ' ' << (rand() % N + 1) << '\n';
	}
	return 0;
}
