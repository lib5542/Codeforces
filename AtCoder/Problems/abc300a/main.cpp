#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;

    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        if (c == A+B) cout << i+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}