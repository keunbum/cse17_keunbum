#include <stdio.h>

#define N 1001

int cnt[128];

int main() {
	char c;
	while ((c = getchar()) != '\n') {
		cnt[c]++;
	}
	while ((c = getchar()) != '\n') {
		cnt[c]--;
	}
	int ans = 0;
	for (int i = 0; i < 128; i++) {
		ans += abs(cnt[i]);
	}
	printf("%d\n", ans);
	return 0;
}
