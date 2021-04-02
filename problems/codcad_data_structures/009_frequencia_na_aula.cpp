#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set<int> students;
    int n, student_id;
    cin >> n;
    while (n--) {
        cin >> student_id;
        students.insert(student_id);
    }
    cout << students.size() << "\n";

    return 0;
}
