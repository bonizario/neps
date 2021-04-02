#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Interval;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int beach_length, total_sellers;
    cin >> beach_length >> total_sellers;

    if (beach_length == 0 || total_sellers == 0) return 0;

    vector<Interval> sellers(total_sellers);
    for (int i = 0, start, end; i < total_sellers; i++) {
        cin >> start >> end;
        sellers[i] = Interval(start, end);
    }

    sort(sellers.begin(), sellers.end(), less<Interval>());
    vector<Interval> intervals = {Interval(sellers[0].first, sellers[0].second)};

    for (int i = 1, last_pos = 0; i < total_sellers; i++) {
        auto& [start, end] = sellers[i];
        auto& [previous_start, previous_end] = intervals[last_pos];
        if (start > previous_end) {
            intervals.push_back(Interval(start, end));
            last_pos++;
        } else if (end > previous_end) {
            intervals[last_pos].second = end;
        }
    }

    for (auto& [start, end] : intervals) {
        cout << start << " " << end << "\n";
    }

    return 0;
}
