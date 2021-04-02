#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    bool valid;
    string expression;
    stack<char> stk;
    cin >> t >> ws;
    while (t--) {
        valid = true;
        cin >> expression;
        for (auto character : expression) {
            if (character == '(' || character == '[' || character == '{') {
                stk.push(character);
            } else if (stk.empty()) {
                valid = false;
                break;
            } else if (character == ')' && stk.top() == '(') {
                stk.pop();
            } else if (character == ']' && stk.top() == '[') {
                stk.pop();
            } else if (character == '}' && stk.top() == '{') {
                stk.pop();
            } else {
                valid = false;
                break;
            }
        }
        if (!stk.empty()) {
            valid = false;
        }
        cout << (valid ? "S\n" : "N\n");

        while (!stk.empty()) stk.pop();
    }

    return 0;
}
