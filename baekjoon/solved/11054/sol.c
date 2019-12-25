#include <stdio.h>

#define N 1234

int a[N];
int dpa[N], dpb[N];

inline int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	scanf("%d", &n);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		dpa[i] = dpb[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				dpa[i] = max(dpa[i], dpa[j] + 1);
			} else
			if (a[i] < a[j]) {
				dpb[i] = max(dpb[i], max(dpa[j], dpb[j]) + 1);
			}
		}
		ans = max(ans, max(dpa[i], dpb[i]));
	}
	printf("%d\n", ans);
	return 0;
}
