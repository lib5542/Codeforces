#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S, T;
    cin >> S >> T;

    vector<int> sCounter(26, 0);
    vector<int> tCounter(26, 0);

    bool is_atcoder[26] = {false};
    for (char c : "atcoder") {
        if (c != '\0') is_atcoder[c-'a'] = true;
    }


    int sG = 0;
    int tG = 0;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '@') sG++;
        else sCounter[S[i]-'a']++;

        if (T[i] == '@') tG++;
        else tCounter[T[i]-'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (sCounter[i] > tCounter[i]) {
            if (is_atcoder[i]) tG -= (sCounter[i]-tCounter[i]);
            else {
                tG = -1;
                break;
            }
        }
        if (sCounter[i] < tCounter[i]) {
            if (is_atcoder[i]) sG -= (tCounter[i]-sCounter[i]);
            else {
                sG = -1;
                break;
            }
        }
    }
    if (tG < 0 || sG < 0) cout << "No";
    else cout << "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}