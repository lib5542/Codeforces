#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    set<pair<string, string>> strings;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        string s2 = "";
        for (int j = 0; j < s.size(); j++) {
            s2 += s[s.size()-j-1];
        }
        if (s < s2) {
            strings.insert(pair(s, s2));
        } else {
            strings.insert(pair(s2, s));
        }
    }

    cout << strings.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}