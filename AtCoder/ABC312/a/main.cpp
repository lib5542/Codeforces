#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;

    set<string> ss = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    if (ss.find(S) == ss.end()) {
        cout << "No";
    } else cout << "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}