#include <stdio.h>

int a[13], b[6];

void Dfs(int k, int d, int pos) {
	if (d == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d%c", b[i], i == 5 ? '\n' : ' ');
		}
		return;
	}
	for (int i = pos; i < k; i++) {
		b[d] = a[i];
		Dfs(k, d + 1, i + 1);
	}
}

int main() {
	while (1) {
		int k;
		scanf("%d", &k);
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", a + i);
		}
		Dfs(k, 0, 0);
		puts("");
	}
	return 0;
}
