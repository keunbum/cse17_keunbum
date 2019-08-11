#include <stdio.h>

#define MAX (int) 1e9

int n;
int max = -MAX;
int min = MAX;
int a[12];

void Dfs(int v, int x, int y, int z, int w, int val) {
	if (x < 0 || y < 0 || z < 0 || w < 0) {
		return;
	}
	if (v == n) {
		if (max < val) max = val;
		if (min > val) min = val;
		return;
	}
	Dfs(v + 1, x - 1, y, z, w, val + a[v]);
	Dfs(v + 1, x, y - 1, z, w, val - a[v]);
	Dfs(v + 1, x, y, z - 1, w, val * a[v]);
	Dfs(v + 1, x, y, z, w - 1, val / a[v]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	int x, y, z, w;
	scanf("%d %d %d %d", &x, &y, &z, &w);
	Dfs(1, x, y, z, w, a[0]);
	printf("%d\n\%d\n", max, min);
	return 0;
}
