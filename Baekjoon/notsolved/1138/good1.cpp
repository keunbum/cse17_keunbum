#include <stdio.h>
int ans[15];
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		scanf("%d", &t);
		for(j = 1; j <= N; j++) {
			if(ans[j] != 0) continue;
			t--;
			if(t == -1) {
				ans[j] = i;
				break;
			}
		}
	}
	for(i = 1; i <= N; i++) printf("%d ", ans[i]);
	return 0;
}
