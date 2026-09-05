#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int first;
    cin >> first;

    int m = -1;
    for (int i = 1; i < N; i++) {
        int t;
        cin >> t;
        m = max(m, t);
    }

    if (first - m > 0) cout << 0;
    else cout << m - first+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}