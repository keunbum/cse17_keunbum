#include <stdio.h>
#include <stdlib.h>

const int INF = (int) 1e9;

int a[123456];

int Cmp(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

int LDis(int x, int m) {
	int low = 0;
	int high = m - 1;
	while (low < high) {
		int mid = (low + high + 1) >> 1;
		if (a[mid] <= x) {
			low = mid;
		} else {
			high = mid - 1;
		}
	}
	int res = x - a[(low + high + 1) >> 1];
	return res >= 0 ? res : INF;
}

int RDis(int x, int m) {
	int low = 0;
	int high = m - 1;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (a[mid] >= x) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	int res = a[(low + high) >> 1] - x;
	return res >= 0 ? res : INF;
}

int main() {
	int m, n, l;
	scanf("%d %d %d", &m, &n, &l);
	for (int i = 0; i < m; i++) {
		scanf("%d", a + i);
	}
	qsort(a, m, sizeof(int), Cmp);
	int ans = 0;
	while (n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (LDis(x, m) <= l - y || RDis(x, m) <= l - y) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
