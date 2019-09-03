#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 10000
#define MAX_LEAF 32768
#define MAX_SEG (2 * MAX_LEAF + 1)

typedef struct Event Event;

struct Event {
	int x;
	int ya;
	int yb;
	int type;
};

Event a[N + N];

int val[MAX_SEG], add[MAX_SEG];

int Cmp(const void *a, const void *b) {
	return (*(Event *) a).x - (*(Event *) b).x;
}

void Modify(int x, int l, int r, int ll, int rr, int v) {
	if (ll <= l && r <= rr) {
		add[x] += v;
		return;
	}
	int y = (l + r) >> 1;
	if (ll <= y) {
		Modify(x + x, l, y, ll, rr, v);
	}
	if (rr > y) {
		Modify(x + x + 1, y + 1, r, ll, rr, v);
	}
	val[x] = 0;
	val[x] += add[x + x] > 0 ? (y - l + 1) : val[x + x];
	val[x] += add[x + x + 1] > 0 ? (r - y) : val[x + x + 1];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int xa, ya, xb, yb;
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		yb--;
		a[i].x = xa; a[i].ya = ya; a[i].yb = yb; a[i].type = 1;
		a[i + n].x = xb; a[i + n].ya = ya; a[i + n].yb = yb; a[i + n].type = -1;
	}
	qsort(a, n + n, sizeof(Event), Cmp);
	int ans = 0;
	for (int i = 0; i < n + n - 1; i++) {
		Modify(1, 0, MAX_LEAF, a[i].ya, a[i].yb, a[i].type);
		ans += (a[i + 1].x - a[i].x) * val[1];
	}
	printf("%d\n", ans);
	return 0;
}
