#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    bool a = false;
    bool b = false;
    bool c = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') a = true;
        if (s[i] == 'B') b = true;
        if (s[i] == 'C') c = true;

        if (a && b && c) {
            cout << i+1;
            return;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}