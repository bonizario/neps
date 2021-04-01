#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	bool valid = true;
    int n, stack = 0;
    string line;

    cin >> n >> ws;
	while (n--) {
        getline(cin, line);
        for (char c : line) {
            if (c == '{') stack++;
            else if (c == '}') stack --;
            if (stack < 0) {
                valid = false;
                break;
            }
        }
    }

    if (stack) valid = false;
    cout << (valid ? "S\n" : "N\n");

    return 0;
}
