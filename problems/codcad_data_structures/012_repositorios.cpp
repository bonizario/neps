#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<int, int> internet_apps;
    map<int, int> installed_apps;
    int total_installed_apps, total_internet_apps, app_id, app_version;
    cin >> total_installed_apps >> total_internet_apps;

    for (int i = 0; i < total_installed_apps; ++i) {
        cin >> app_id >> app_version;
        installed_apps[app_id] = app_version;
    }

    for (int i = 0; i < total_internet_apps; ++i) {
        cin >> app_id >> app_version;
        auto it = internet_apps.find(app_id);
        if (it == internet_apps.end() || it->second < app_version) {
            internet_apps[app_id] = app_version;
        }
    }

    for (auto& [internet_app_id, internet_app_version] : internet_apps) {
        auto it = installed_apps.find(internet_app_id);
        if (it == installed_apps.end() || it->second < internet_app_version) {
            cout << internet_app_id << " " << internet_app_version << "\n";
        }
    }

    return 0;
}
