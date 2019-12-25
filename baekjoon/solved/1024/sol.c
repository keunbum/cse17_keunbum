#include <stdio.h>

int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = l; i <= 100; i++) {
		double foo = ((n * (2.0 / i)) - i + 1) * 0.5;
		if (foo >= 0 && (foo == (int) foo)) {
			int s = (int) foo;
			for (int j = 0; j < i; j++) {
				printf("%d%c", s + j, j < i - 1 ? ' ' : '\n');
			}
			return 0;
		}
	}
	puts("-1");
	return 0;
}
