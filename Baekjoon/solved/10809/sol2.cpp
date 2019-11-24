#include <cstdio>
#include <cstring>

using namespace std;

const int LEN = 100;
char s[LEN];
int a[128];

int main() {
	fgets(s, LEN, stdin);
	memset(a, -1, sizeof(a));
	for (int i = 99; ~i; i--) {
		a[s[i]] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d%c", a[i + 'a'], i < 25 ? ' ' : '\n');
	}
	return 0; 
}
