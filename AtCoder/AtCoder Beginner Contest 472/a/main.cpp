#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') cout << 'A';
        else cout << '.';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}