#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> alice_cards;
    set<int> beatriz_cards;

    int card, total_alice, total_beatriz;
    cin >> total_alice >> total_beatriz;
    while (total_alice--) {
        cin >> card;
        alice_cards.insert(card);
    }
    while (total_beatriz--) {
        cin >> card;
        beatriz_cards.insert(card);
    }

    int tradable_alice = 0, tradable_beatriz = 0;
    for (auto& c : alice_cards) {
        if (beatriz_cards.find(c) == beatriz_cards.end()) tradable_alice++;
    }
    for (auto& c : beatriz_cards) {
        if (alice_cards.find(c) == alice_cards.end()) tradable_beatriz++;
    }

    cout << (tradable_alice < tradable_beatriz ? tradable_alice : tradable_beatriz) << "\n";

    return 0;
}
