#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, leave;
    cin >> n;
    vector<int> queue(n);
    for (int i = 0; i < n; i++) {
        cin >> queue[i];
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> leave;
        queue.erase(remove(queue.begin(), queue.end(), leave), queue.end());
    }

    int t = queue.size() - 1;
    for (int i = 0; i < t; i++) {
        cout << queue[i] << " ";
    }
    cout << queue[t] << "\n";

    return 0;
}
