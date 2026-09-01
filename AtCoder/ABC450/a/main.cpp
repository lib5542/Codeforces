#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    if (N > 1) {
        for (int i = N; i > 1; i--) {
            cout << i << ",";
        }
    }
    cout << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}