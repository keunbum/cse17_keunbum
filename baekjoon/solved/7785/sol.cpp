#include <bits/stdc++.h>

using namespace std;

struct St {
	bool operator()(const string& i, const string& j) const {
		return i > j;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	set<string, St> on;
	while (n--) {
		string s, log;
		cin >> s >> log;
		if (log == "enter") {
			on.insert(s);
		} else {
			on.erase(s);
		}
	}
	for (string s : on) {
		cout << s << '\n';
	}
	return 0;
}
