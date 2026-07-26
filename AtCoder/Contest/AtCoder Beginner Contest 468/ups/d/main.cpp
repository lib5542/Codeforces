#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S;
    cin >> S;

    int N = S.size();
    int counter = 0;

    for (int i = 0; i < N; i++) {
        int wr = 0;
        for (int j = 0; i-j >= 0 && i+j < N; j++) {
            if (S[i-j] != S[i+j]) wr++;
            if (wr > 1) break;
            counter++;
        }
        wr = 0;
        if (i > 0) {
            for (int j = 1; i-j >= 0 && i+j-1 < N; j++) {
                if (S[i-j] != S[i+j-1]) wr++;
                if (wr > 1) break;
                counter++;
            }
        }
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}