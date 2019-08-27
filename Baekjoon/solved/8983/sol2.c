#include <stdio.h>
#include <stdlib.h>

typedef struct Point Point;

#define N ((int) 1e5)
#define M N

int a[M];

struct Point {
	int x;
	int y;
} b[N];

int Cmp1(const void *a, const void *b) {
	return *(int *) a - *(int *) b;
}

int Cmp2(const void *a, const void *b) {
	return (*(Point *) a).x - (*(Point *) b).x;
}

int main() {
	int m, n, l;
	scanf("%d %d %d", &m, &n, &l);
	for (int i = 0; i < m; i++) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &b[i].x, &b[i].y);
	}
	qsort(a, m, sizeof(int), Cmp1);
	qsort(b, n, sizeof(Point), Cmp2);
	int ans = 0;
	int p = 1;
	for (int i = 0; i < n; i++) {
		while (p < m && a[p] < b[i].x) {
			p++;
		}
		if (abs((a[p - 1] - b[i].x)) + b[i].y <= l || (p < m && abs(a[p] - b[i].x) + b[i].y <= l)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
