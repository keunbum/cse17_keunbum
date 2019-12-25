#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N ((int) 1e6)

char s[N + 2];
char ans[N + 2];

int main() {
	fgets(s, N + 2, stdin);
	int l;
	for (l = 0; s[l] != '\n'; l++) ;
	s[l] = 0;
	int e = N;
	for (int i = l - 1; i >= 0; i -= 3) {
		int foo = 0;
		for (int j = 2; j >= 0; j--) {
			if (i - j >= 0) {
				foo = foo * 2 + (s[i - j] - '0'); 
			}
		}
//		printf("foo = %d\n", foo);
		ans[e--] = foo + '0';
	}
	int st;
	for (st = 0; st <= N; st++) {
		if (ans[st] > 0) {
			break;
		}
	}
	puts(ans + st);
	return 0;
}
