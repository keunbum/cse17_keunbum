#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX 333335

char s[MAX];

int main() {
	scanf("%s", s);
	if (s[0] == '0') {
		puts("0");
		return 0;
	}
	for (int i = 0; s[i]; i++) {
		char buf[4];
		buf[3] = 0;
		int n = s[i] - '0';
		for (int p = 2; ~p; p--) {
			buf[p] = (n & 1) + '0';
			n >>= 1;
		}
		int p = 0;
		if (i == 0) {
			while (buf[p] == '0') p++;
		}
		fputs(buf + p, stdout);
	}
	puts("");
  return 0;
}
