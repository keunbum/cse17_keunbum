#include <stdio.h>

#define N 123456

char s[N];
int a[N + N];

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

int main() {
	scanf("%s", s);
	int n;
	for (n = 0; s[n]; n++) ;
	int ans = 1;
	int l = -1, r = -1;
	for (int z = 0; z < n + n - 1; z++) {
		int i = (z + 1) >> 1;
		int j = z >> 1;
		int p = (i >= r ? 0 : min(r - i, a[2 * (l + r) - z]));
		while (j + p + 1 <= n && i - p - 1 >= 0) {
			if (s[j + p + 1] != s[i - p - 1]) break;
			p++;
		}
		if (j + p > r) {
			l = i - p;
			r = j + p;
		}
		a[z] = p;
		ans = max(ans, a[z] * 2 + !(z & 1));
	}
	return !printf("%d\n", ans);
}
