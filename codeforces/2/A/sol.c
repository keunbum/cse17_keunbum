#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1234

char s[N];
char ss[N][33];
int tt[N], qq[N], sum[N], max[N], it[N];

int main() {
	int i, j, n, m, t, q, mx, mi, ans_i;
	scanf("%d", &n);
	m = 0;
	for (i = 1; i <= n; i++) {
		scanf("%s %d", s, &q);
		t = 0;
		for (j = 1; j <= m; j++) {
			if (strcmp(ss[j], s) == 0) {
				t = j;
				break;
			}
		}
		if (t == 0) {
			++m;
			strcpy(ss[m], s);
			sum[m] = 0;
			it[m] = 0;
			t = m;
		}
		tt[i] = t;
		qq[i] = q;
		sum[t] += q;
	}
	memset(max, 0, sizeof(max));
	for (i = 1; i <= n; i++) {
		max[tt[i]] += qq[i];
		if (it[tt[i]] == 0 && max[tt[i]] >= sum[tt[i]]) {
			it[tt[i]] = i;
		}
	}
	mx = 0, mi = 0, ans_i = 0;
	for (i = 1; i <= m; i++) {
		if (sum[i] > mx || (sum[i] == mx && it[i] < mi)) {
			mx = sum[i];
			mi = it[i];
			ans_i = i;
		}
	}
	printf("%s\n", ss[ans_i]);
	return 0;
}
