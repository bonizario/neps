#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int G[MAXN], S[MAXN];

int Find(int a) {
    if (G[a] == a) return a;
    return G[a] = Find(G[a]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (S[a] > S[b]) {
        G[b] = a, S[a] += 1;
    } else {
        G[a] = b, S[b] += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k, a, b;
    char operation;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        G[i] = i, S[i] = 1;
    }

    while (k--) {
        cin >> operation >> a >> b;
        if (operation == 'C') {
            bool same_parent = Find(a) == Find(b);
            cout << (same_parent ? "S\n" : "N\n");
        } else {
            Union(a, b);
        }
    }

    return 0;
}
