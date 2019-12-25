#include <cstdio>
#include <cstdlib>

using namespace std;

inline bool IsHan(int n) {
	if (n < 100) {
		return true;
	}
	int a = n / 100;
	int b = (n / 10) % 10;
	int c = n % 10;
	return b + b == a + c;
}

int main() {
	char s[11];
	int n = atoi(fgets(s, 11, stdin));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += IsHan(i);
	}
	snprintf(s, 11, "%d", ans);
	return !puts(s);
}
