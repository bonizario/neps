#include <bits/stdc++.h>
using namespace std;

typedef struct Card {
    int value;
    char suit;
    bool has_triggered = false;
} Card;

struct Cmp {
    bool operator()(const Card& a, const Card& b) const {
        if (a.value != b.value) {
            return a.value > b.value;
        }
        return a.suit > b.suit;
    }
};

typedef struct Player {
    multiset<Card, Cmp> hand;
} Player;

char card_suit;
bool clockwise;
Card last_discarded_card;
int total_players, initial_hand, total_cards, card_value, current_player, winner;

bool find_by_suit(const Card& player_card);
bool find_by_value(const Card& player_card);
bool discard(Player& player, stack<Card>& discard_pile);
void draw(Player& player, queue<Card>& draw_pile);
void play(Player& player, stack<Card>& discard_pile, queue<Card>& draw_pile);
void pass_turn_to_next_player(void);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> total_players >> initial_hand >> total_cards >> ws) {
        if (total_players == 0 && initial_hand == 0 && total_cards == 0) break;

        Card card;
        queue<Card> draw_pile;
        stack<Card> discard_pile;
        vector<Player> players(total_players);

        for (int i = 0; i < total_players; i++) {
            for (int j = 0; j < initial_hand; j++) {
                cin >> card_value >> ws >> card_suit;
                card.suit = card_suit;
                card.value = card_value;
                players[i].hand.insert(card);
            }
        }

        current_player = 0, clockwise = true, winner = -1;

        cin >> card_value >> ws >> card_suit;
        card.value = card_value;
        card.suit = card_suit;

        if (card_value == 12) {
            card.has_triggered = true;
            clockwise = false;
        }

        discard_pile.push(card);

        int draw_pile_size = total_cards - (total_players * initial_hand + 1);

        for (int i = 0; i < draw_pile_size; i++) {
            cin >> card_value >> ws >> card_suit;
            card.suit = card_suit;
            card.value = card_value;
            draw_pile.push(card);
        }

        while (winner == -1) {
            last_discarded_card = discard_pile.top();

            play(players[current_player], discard_pile, draw_pile);

            if (players[current_player].hand.empty()) winner = current_player;

            pass_turn_to_next_player();
        }

        cout << winner + 1 << "\n";
    }

    return 0;
}

bool find_by_value(const Card& player_card) {
    return player_card.value == last_discarded_card.value;
}

bool find_by_suit(const Card& player_card) {
    return player_card.suit == last_discarded_card.suit;
}

bool discard(Player& player, stack<Card>& discard_pile) {
    auto it_by_value = find_if(player.hand.begin(), player.hand.end(), find_by_suit);
    auto it_by_suit = find_if(player.hand.begin(), player.hand.end(), find_by_value);
    auto it = player.hand.begin();

    if (it_by_suit != player.hand.end() && it_by_value != player.hand.end()) {
        if ((*it_by_suit).value >= (*it_by_value).value) {
            it = it_by_suit;
        } else {
            it = it_by_value;
        }
    } else if (it_by_suit == player.hand.end() && it_by_value != player.hand.end()) {
        it = it_by_value;
    } else if (it_by_suit != player.hand.end() && it_by_value == player.hand.end()) {
        it = it_by_suit;
    } else {
        return false;
    }
    discard_pile.push(*it);
    if ((*it).value == 12) {
        clockwise = !clockwise;
        discard_pile.top().has_triggered = true;
    }
    player.hand.erase(it);
    return true;
}

void draw(Player& player, queue<Card>& draw_pile) {
    if (draw_pile.empty()) return;
    player.hand.insert(draw_pile.front());
    draw_pile.pop();
}

void play(Player& player, stack<Card>& discard_pile, queue<Card>& draw_pile) {
    int last_discarded_card_value = last_discarded_card.value;
    bool has_triggered = last_discarded_card.has_triggered;

    if (!has_triggered) {
        discard_pile.top().has_triggered = true;
        if (last_discarded_card_value == 7) {
            draw(player, draw_pile);
            draw(player, draw_pile);
            return;
        } else if (last_discarded_card_value == 1) {
            draw(player, draw_pile);
            return;
        } else if (last_discarded_card_value == 11) {
            return;
        }
    }

    bool discarded_successfully = discard(player, discard_pile);
    if (!discarded_successfully) {
        draw(player, draw_pile);
        discard(player, discard_pile);
    }
}

void pass_turn_to_next_player(void) {
    current_player += (clockwise ? 1 : -1);
    if (current_player == total_players)
        current_player -= total_players;
    else if (current_player == -1)
        current_player += total_players;
}

/*
==================================== DEBUG =====================================
#include <bits/stdc++.h>
using namespace std;

typedef struct Card {
    int value;
    char suit;
    bool has_triggered = false;
} Card;

struct Cmp {
    bool operator()(const Card& a, const Card& b) const {
        if (a.value != b.value) {
            return a.value > b.value;
        }
        return a.suit > b.suit;
    }
};

typedef struct Player {
    multiset<Card, Cmp> hand;
} Player;

char card_suit;
bool clockwise;
Card last_discarded_card;
int total_players, initial_hand, total_cards, card_value, current_player, winner;

bool find_by_suit(const Card& player_card);
bool find_by_value(const Card& player_card);
bool discard(Player& player, stack<Card>& discard_pile);
void draw(Player& player, queue<Card>& draw_pile);
void play(Player& player, stack<Card>& discard_pile, queue<Card>& draw_pile);
void pass_turn_to_next_player(void);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> total_players >> initial_hand >> total_cards >> ws) {
        if (total_players == 0 && initial_hand == 0 && total_cards == 0) break;

        Card card;
        queue<Card> draw_pile;
        stack<Card> discard_pile;
        vector<Player> players(total_players);

        for (int i = 0; i < total_players; i++) {
            for (int j = 0; j < initial_hand; j++) {
                cin >> card_value >> ws >> card_suit;
                card.suit = card_suit;
                card.value = card_value;
                players[i].hand.insert(card);
            }
        }

        current_player = 0, clockwise = true, winner = -1;

        cin >> card_value >> ws >> card_suit;
        card.value = card_value;
        card.suit = card_suit;

        if (card_value == 12) {
            card.has_triggered = true;
            clockwise = false;
        }

        discard_pile.push(card);

        int draw_pile_size = total_cards - (total_players * initial_hand + 1);

        for (int i = 0; i < draw_pile_size; i++) {
            cin >> card_value >> ws >> card_suit;
            card.suit = card_suit;
            card.value = card_value;
            draw_pile.push(card);
        }

        // int turn = 1;
        while (winner == -1) {
            // cout << "TURN: " << turn++ << "\n";
            last_discarded_card = discard_pile.top();

            // cout << "CURRENTPLAYER: " << current_player << "\n";
            // cout << "CURRENTPLAYER HAND BEFORE:\n";
            // for (auto const c : players[current_player].hand) {
            //     cout << "CARD: (" << c.value << ", " << c.suit << ", " << c.has_triggered << ")\n";
            // }
            // cout << "LAST DISCARDED CARD: " << last_discarded_card.value << " " << last_discarded_card.suit << " " << last_discarded_card.has_triggered << "\n";

            play(players[current_player], discard_pile, draw_pile);

            if (players[current_player].hand.empty()) winner = current_player;

            // cout << "CURRENTPLAYER HAND AFTER:\n";
            // for (auto const c : players[current_player].hand) {
            //     cout << "CARD: (" << c.value << ", " << c.suit << ", " << c.has_triggered << ")\n";
            // }

            pass_turn_to_next_player();
        }

        cout << winner + 1 << "\n";

        // cout << "\nPLAYERS\n";
        // for (int i = 0; i < total_players; i++) {
        //     cout << "Player " << i << "\n";
        //     for (auto const c : players[i].hand) {
        //         cout << c.value << " " << c.suit << " " << c.has_triggered << "\n";
        //     }
        // }

        // cout << "\nDISCARD PILE\n";
        // while (!discard_pile.empty()) {
        //     const auto c = discard_pile.top();
        //     cout << c.value << " " << c.suit << " " << c.has_triggered << "\n";
        //     discard_pile.pop();
        // }

        // cout << "\nDRAW PILE\n";
        // while (!draw_pile.empty()) {
        //     const auto c = draw_pile.front();
        //     cout << c.value << " " << c.suit << " " << c.has_triggered << "\n";
        //     draw_pile.pop();
        // }
    }

    return 0;
}

bool find_by_value(const Card& player_card) {
    return player_card.value == last_discarded_card.value;
}

bool find_by_suit(const Card& player_card) {
    return player_card.suit == last_discarded_card.suit;
}

bool discard(Player& player, stack<Card>& discard_pile) {
    auto it_by_value = find_if(player.hand.begin(), player.hand.end(), find_by_suit);
    auto it_by_suit = find_if(player.hand.begin(), player.hand.end(), find_by_value);
    auto it = player.hand.begin();

    if (it_by_suit != player.hand.end() && it_by_value != player.hand.end()) {
        if ((*it_by_suit).value >= (*it_by_value).value) {
            it = it_by_suit;
        } else {
            it = it_by_value;
        }
    } else if (it_by_suit == player.hand.end() && it_by_value != player.hand.end()) {
        it = it_by_value;
    } else if (it_by_suit != player.hand.end() && it_by_value == player.hand.end()) {
        it = it_by_suit;
    } else {
        return false;
    }
    discard_pile.push(*it);
    if ((*it).value == 12) {
        clockwise = !clockwise;
        discard_pile.top().has_triggered = true;
    }
    // cout << "CARD DISCARDED: (" << (*it).value << ", " << (*it).suit << ", " << (*it).has_triggered << ")\n";
    player.hand.erase(it);
    return true;
}

void draw(Player& player, queue<Card>& draw_pile) {
    if (draw_pile.empty()) return;
    // cout << "CARD DRAWED: " << draw_pile.front().value << " " << draw_pile.front().suit << "\n";
    player.hand.insert(draw_pile.front());
    draw_pile.pop();
}

void play(Player& player, stack<Card>& discard_pile, queue<Card>& draw_pile) {
    int last_discarded_card_value = last_discarded_card.value;
    bool has_triggered = last_discarded_card.has_triggered;

    if (!has_triggered) {
        discard_pile.top().has_triggered = true;
        if (last_discarded_card_value == 7) {
            draw(player, draw_pile);
            draw(player, draw_pile);
            return;
        } else if (last_discarded_card_value == 1) {
            draw(player, draw_pile);
            return;
        } else if (last_discarded_card_value == 11) {
            return;
        }
    }

    bool discarded_successfully = discard(player, discard_pile);
    if (!discarded_successfully) {
        draw(player, draw_pile);
        discard(player, discard_pile);
    }
}

void pass_turn_to_next_player(void) {
    current_player += (clockwise ? 1 : -1);
    if (current_player == total_players)
        current_player -= total_players;
    else if (current_player == -1)
        current_player += total_players;

    // cout << "NEXT PLAYER: " << current_player << "\n\n";
}

*/
