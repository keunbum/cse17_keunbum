#include <cstdio>
#include <algorithm>

using namespace std;

char a[200002];
int d[200002];

int main() {
	int i, j, k, l, n, r = 0;
	scanf("%s", a);
	for (n = 0; a[n]; n++);
	n = n + n + 1;
	for (i = n - 1; i >= 0; i--) a[i] = i & 1 ? a[i >> 1] : 32;
	k = l = 0;
	for (i = 0; i < n; i++) {
		for (j = i <= l ? min(l - i, d[k + k - i]) : 0; i - j && i + j + 1 < n && a[i - j - 1] == a[i + j + 1]; j++);
		d[i] = j;
		if (j > r) r = j;
		if (i + j > l) {
			k = i;
			l = i + j;
		}
	}
	printf("%d\n", r);
}
