#include <bits/stdc++.h>
using namespace std;

void print_line(vector<string> words);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        map<string, string> dictionary;
        string word, line, translated_line;
        int total_dictionary_words, total_song_lines;
        cin >> total_dictionary_words >> total_song_lines;
        while (total_dictionary_words--) {
            getline(cin >> ws, line);
            getline(cin >> ws, translated_line);
            dictionary[line] = translated_line;
        }
        while (total_song_lines--) {
            getline(cin >> ws, line);
            stringstream ss(line);
            vector<string> words;
            while (getline(ss, word, ' ')) {
                if (dictionary.find(word) != dictionary.end()) {
                    words.push_back(dictionary[word]);
                } else {
                    words.push_back(word);
                }
            }
            print_line(words);
        }
        cout << "\n";
    }

    return 0;
}

void print_line(vector<string> words) {
    int end = words.size() - 1;
    for (int i = 0; i < end; ++i) {
        cout << words[i] << " ";
    }
    cout << words[end] << "\n";
}
