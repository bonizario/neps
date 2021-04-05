#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d, ans = 0, sum = 0, right = 0;
    cin >> n >> d;
    vector<int> pieces(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> pieces[i];
        pieces[i + n] = pieces[i];
    }
    for (int i = 0; i < n; ++i) {
        while (right < i + n && sum < d) {
            sum += pieces[right++];
        }
        if (sum == d) ans++;
        sum -= pieces[i];
    }
    cout << ans << "\n";

    return 0;
}
