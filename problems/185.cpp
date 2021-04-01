#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, component; cin >> n;
    unordered_map<int, int> components;
    map<char, int> models = {{'A', 0}, {'B', 0}, {'C', 0}};

    for (int i = 0; i < n; i++) {
        cin >> component;
        components[component]++;
        if (components[1] && components[3] && components[5]) {
            components[1]--, components[3]--, components[5]--;
            models['A']++;
        }
        if (components[1] && components[4]) {
            components[1]--, components[4]--;
            models['B']++;
        }
        if (components[2] && components[4]) {
            components[2]--, components[4]--;
            models['C']++;
        }
    }

    for (auto& [model, quantity] : models) {
        cout << model << ": " << quantity << "\n";
    }

    return 0;
}
