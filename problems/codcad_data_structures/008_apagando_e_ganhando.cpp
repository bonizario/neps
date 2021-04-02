#include <bits/stdc++.h>
using namespace std;

void erase_digit(list<char>& digits, list<char>::iterator& it);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    char digit;
    while (cin >> n >> d >> ws) {
        if (n == 0 && d == 0) break;

        list<char> digits;
        for (int i = 0; i < n; i++) {
            cin >> digit;
            digits.push_back(digit);
        }

        auto it = digits.begin();
        auto end = --digits.end();

        while (it != end) {
            if (d == 0) break;
            char current_digit = *it;
            it++;
            char next_digit = *(it);
            it--;
            if (current_digit < next_digit) {
                erase_digit(digits, it);
                d--;
            } else {
                it++;
            }
        }

        it = digits.end();
        it--;
        while (it != digits.begin()) {
            if (d == 0) break;
            char current_digit = *it;

            it--;
            char previous_digit = *(it);
            it++;

            if (previous_digit >= current_digit) {
                erase_digit(digits, it);
                d--;
            } else {
                it++;
            }
        }

        for (it = digits.begin(); it != digits.end(); it++) {
            cout << *it;
        }
        cout << "\n";
    }

    return 0;
}

void erase_digit(list<char>& digits, list<char>::iterator& it) {
    if (it != digits.begin()) {
        it--;
        list<char>::iterator previous_it = it;
        it++;
        digits.erase(it);
        it = previous_it;
    } else {
        digits.erase(it);
        it = digits.begin();
    }
}
