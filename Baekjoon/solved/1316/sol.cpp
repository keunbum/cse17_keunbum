#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXL = 100;

char s[MAXL + 1];
bool chk[128];

int main() {
	int n = atoi(fgets(s, MAXL + 1, stdin));
	int ans = 0;
	while (n--) {
		bool ok = true;
		fgets(s, MAXL + 1, stdin);
		memset(chk, false, sizeof(chk));
		for (int i = 0; s[i]; i++) {
			if (chk[s[i]] && s[i - 1] != s[i]) {
				ok = false;
				break;
			}
			chk[s[i]] = true;
		}
		ans += (int) (ok);
	}
	snprintf(s, MAXL + 1, "%d", ans);
	return !puts(s);
}
