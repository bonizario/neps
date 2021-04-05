#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int G[MAXN], S[MAXN], P[MAXN];

int Find(int a) {
    if (G[a] == a) return a;
    return G[a] = Find(G[a]);
}

void Union(int a, int b) {
    if (S[a] > S[b]) {
        G[b] = a, S[a] += S[b];
    } else {
        G[a] = b, S[b] += S[a];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, initial_points, operation;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            cin >> initial_points;
            G[i] = i, S[i] = initial_points;
        }

        int wins = 0;
        while (m--) {
            cin >> operation >> a >> b;
            a = Find(a), b = Find(b);
            if (operation == 1) {
                Union(a, b);
            } else {
                int rafa_guild = Find(1);
                if ((a == rafa_guild && S[a] > S[b]) ||
                    (b == rafa_guild && S[b] > S[a])) wins++;
            }
        }
        cout << wins << "\n";
    }

    return 0;
}
