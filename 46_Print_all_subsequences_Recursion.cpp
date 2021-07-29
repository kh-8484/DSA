#include <iostream>
using namespace std;

void func(string t, int i, int n, string s) {
	if (i == n) {
		cout << t << endl;
	}
	else {
		func(t, i + 1, n, s);
		t = t + s[i];
		func(t, i + 1, n, s);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	func("", 0, s.length(), s);

	return 0;
}