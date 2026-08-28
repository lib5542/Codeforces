#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    string S;
    cin >> N;
    cin >> S;

    bool oo = true;

    for (int i = 0; i < N; i++) {
        if (S[i] != 'o') {
            oo = false;
        }
        if (!oo) cout << S[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}