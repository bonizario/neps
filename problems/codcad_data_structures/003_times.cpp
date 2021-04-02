#include <bits/stdc++.h>
using namespace std;

typedef pair<int, string> Player;

struct {
    inline bool operator()(const Player& a, const Player& b) {
        return a.second < b.second;
    }
} compare_names;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, skill, current_team = 0;
    cin >> n >> t;
    string name;
    vector<Player> players(n);
    vector<vector<Player>> teams(t);

    for (int i = 0; i < n; i++) {
        cin >> name >> skill;
        players[i] = Player(skill, name);
    }

    sort(players.begin(), players.end(), greater<Player>());

    for (auto& player : players) {
        teams[current_team++].push_back(player);
        if (current_team == t) current_team = 0;
    }

    current_team = 1;
    for (auto& team : teams) {
        cout << "Time " << current_team++ << "\n";
        sort(team.begin(), team.end(), compare_names);
        for (auto& [player_skill, player_name] : team) {
            cout << player_name << "\n";
        }
        cout << "\n";
    }

    return 0;
}
