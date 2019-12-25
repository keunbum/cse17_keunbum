#include <cstdio>

using namespace std;

const int MAX = (int) 1e4;

char s[10];
bool a[MAX + 1];

inline int D(int n) {
	int res = n;
	while (n > 0) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main() {
	for (int i = 1; i <= MAX; i++) {
		int d = D(i);
		if (d <= MAX) {
			a[D(i)] = true;
		}
	}
	for (int i = 1; i <= MAX; i++) {
		if (!a[i]) {
			snprintf(s, 10, "%d", i); 
			puts(s);
		}
	}
	return 0;
}
