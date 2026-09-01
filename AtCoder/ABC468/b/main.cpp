#include <bits/stdc++.h>

using namespace std;

void solve() {
    int M, D;
    cin >> M >> D;

    string S;
    cin >> S;

    vector<bool> watching(M, false);
    for (int i = 0; i < M; i++) {
        if (S[i] == 'G') {
            for (int j = i-D; j <= i+D; j++) {
                if (0 <= j && j < M) watching[j] = true;
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < M; i++) {
        if (watching[i] == false) counter++;
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}