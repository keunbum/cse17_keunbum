#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

int a[42];
char s[5];

int main() {
	while (fgets(s, 5, stdin)) {
		int n = atoi(s);
		a[n % 42] = 1;
	}
	int ans = 0;
	for (int i = 0; i < 42; i++) {
		ans += a[i];
	}
	assert(snprintf(s, 5, "%d", ans) > 0);
	return !puts(s);
}
