#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Event Event;

struct Event {
	int x, y;
	int ty;
};

#define N 75000

Event a[N];
int val[4 * N];

int Cmp1(const void *a, const void *b) {
	Event p = *(Event *) a;
	Event q = *(Event *) b;
	if (p.x != q.x) {
		return p.x - q.x;
	}
	return q.y - p.y;
}

int Cmp2(const void *a, const void *b) {
	return (*(Event *) a).y - (*(Event *) b).y;
}

void Modify(int x, int l, int r, int ll, int rr, int v) {
	if (ll <= l && r <= rr) {
		val[x] += v;
		return;
	}
	int y = (l + r) >> 1;
	if (ll <= y) {
		Modify(x + x, l, y, ll, rr, v);
	}
	if (rr > y) {
		Modify(x + x + 1, y + 1, r, ll, rr, v);
	}
	val[x] = val[x + x] + val[x + x + 1];
}

int Get(int x, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
//		fprintf(stderr, "Get(%d, %d, %d, %d, %d) returns %d\n", x, l, r, ll, rr, val[x]);
		return val[x];
	}
	int y = (l + r) >> 1;
	int res = 0;
	if (rr <= y) {
		res = Get(x + x, l, y, ll, rr);
	} else 
	if (ll > y) {
		res = Get(x + x + 1, y + 1, r, ll, rr);
	} else {
		res = Get(x + x, l, y, ll, rr) + Get(x + x + 1, y + 1, r, ll, rr);
	}
//	fprintf(stderr, "Get(%d, %d, %d, %d, %d) returns %d\n", x, l, r, ll, rr, res);
	return res;
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int qq = 1; qq <= tt; qq++) {
		int n;
		scanf("%d", &n);
		memset(val, 0, sizeof(val));
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i].x, &a[i].y);
			a[i].ty = a[i].y;
		}
		qsort(a, n, sizeof(Event), Cmp2);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && a[i - 1].ty == a[i].ty) {
				a[i].y = a[i - 1].y;
			} else {
				a[i].y = cnt++;
			}
		}
		qsort(a, n, sizeof(Event), Cmp1);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += Get(1, 0, cnt - 1, a[i].y, cnt - 1);
			Modify(1, 0, cnt - 1, a[i].y, a[i].y, 1);
		}
		printf("%lld\n", ans);
	}
//	fprintf(stderr, "%f seconds\n", (float) clock() / CLOCKS_PER_SEC);
	return 0;
}
