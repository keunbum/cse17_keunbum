#include <bits/stdc++.h>

using namespace std;

const int MAX = 600010;

char stka[MAX];
char stkb[MAX];

int main() {
	fgets(stka, MAX, stdin);
	int ta = 0;
	while (stka[ta] != '\n') {
		ta++;
	}
	int tb = 0;
	auto Move = [&](int d) {
		if (ta + d < 0 || tb - d < 0) {
			return;
		}
		if (d > 0) {
			stka[ta++] = stkb[tb - 1];
			tb--;
		} else {
			stkb[tb++] = stka[ta - 1];
			ta--;
		}
	};
	auto Delete = [&]() {
		if (ta > 0) {
			ta--;
		}
	};
	auto Insert = [&](char c) {
		stka[ta++] = c;
	};
	auto Print = [&]() {
		stka[ta] = 0;
		fputs(stka, stdout);
		for (int i = tb - 1; ~i; i--) {
			fputc(stkb[i], stdout);
		}
		fputc('\n', stdout);
	};
	char tmp[11];
	int n = atoi(fgets(tmp, 11, stdin));
	while (n--) {
		fgets(tmp, 11, stdin);
		char cmd = tmp[0];
		if (cmd == 'L') {
			Move(-1);
		} else
		if (cmd == 'D') {
			Move(1);
		} else
		if (cmd == 'B') {
			Delete();
		} else
		if (cmd == 'P') {
			char c = tmp[2];
			Insert(c);
		}
	}
	Print();
	return 0;
}
