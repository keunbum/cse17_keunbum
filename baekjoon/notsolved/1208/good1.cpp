#include <cstdio>

int arr[40], n, s, a[4000001];
long long cnt;

void f(int p, int t) {
	if (p == n / 2) {
		if (t == s)
			cnt++;
		a[t + 2000000]++;

		return;
	}

	f(p + 1, t + arr[p]);
	f(p + 1, t);
}

void g(int p, int t) {
	if (p == n) {
		if (t == s)
			cnt++;
		if (s - t > 2000000 || s - t < -2000000)
			return;
		cnt += a[s - t + 2000000];

		return;
	}

	g(p + 1, t + arr[p]);
	g(p + 1, t);
}

int main() {
	int i;

	scanf("%d %d", &n, &s);

	for (i = 0;i < n;++i)
		scanf("%d", &arr[i]);

	a[2000000]--;
	f(0, 0);
	g(n / 2, 0);

	printf("%lld", cnt - a[s + 2000000] - (s == 0) * 2);

	return 0;
}
