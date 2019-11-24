#include <cstdio>
#include <cstdlib>
#include <numeric>

using namespace std;

int a[42];
char s[5];

int main() {
	while (fgets(s, 5, stdin)) {
		int n = atoi(s);
		a[n % 42] = 1;
	}
	int ans = accumulate(a, a + 42, 0);
	return !printf("%d\n", ans);
}
