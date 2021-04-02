#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int total_cues, cue_length, produced = 0;
    set<int> cue_lengths;
    cin >> total_cues;
    while (total_cues--) {
        cin >> cue_length;
        if (cue_lengths.find(cue_length) == cue_lengths.end()) {
            produced += 2;
            cue_lengths.insert(cue_length);
        } else {
            cue_lengths.erase(cue_length);
        }
    }
    cout << produced << "\n";

    return 0;
}
