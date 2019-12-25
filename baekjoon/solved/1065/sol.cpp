#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

inline bool IsHan(int n) {
	vector<int> a;
	while (n > 0) {
		a.push_back(n % 10);
		n /= 10;
	}
	n = (int) a.size();
	if (n <= 2) {
		return true;
	}
	int d = a[1] - a[0];
	for (int i = 2; i < n; i++) {
		if (d != a[i] - a[i - 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	char s[11];
	int n = atoi(fgets(s, 5, stdin));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (int) IsHan(i);
	}
	snprintf(s, 11, "%d", ans);
	return !puts(s);
}
