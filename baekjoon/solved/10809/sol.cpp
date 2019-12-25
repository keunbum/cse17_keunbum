#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char c;
	int i = 0;
	int a[128];
	memset(a, -1, sizeof(a));
	while ((c = fgetc(stdin)) != '\n') {
		if (a[c - 'a'] == -1) {
			a[c - 'a'] = i;
		}
		i++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%s%d", i == 0 ? "" : " ", a[i]);
	}
	puts("");
	return 0;
}
