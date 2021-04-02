#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<char> teams;
    int goalsLeft, goalsRight;
    for (char team = 'A'; team <= 'P'; team++) {
        teams.push(team);
    }

    for (int i = 0; i < 15; i++) {
        cin >> goalsLeft >> goalsRight;
        if (goalsLeft > goalsRight) {
            teams.push(teams.front());
            teams.pop();
        } else {
            teams.pop();
            teams.push(teams.front());
        }
        teams.pop();
    }

    cout << teams.front() << "\n";

    return 0;
}
