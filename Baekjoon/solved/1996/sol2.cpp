#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

const int DX[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int DY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int grid[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			int c = s[j];
			if (c != '.') {
				grid[i][j] = -1;
				for (int k = 0; k < 8; k++) {
					int u = i + DX[k];
					int v = j + DY[k];
					if (u >= 0 && u < n && v >= 0 && v < n && grid[u][v] >= 0) {
						grid[u][v] += c - '0';
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t = grid[i][j];
			cout << (char) (t > 9 ? 'M' : t >= 0 ? (t + '0') : '*');
		}
		cout << '\n';
	}
	return 0;
}
