#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    map<int, int> m;
    for (int i = 1; i <= 9; i++) {
        m[i] = (i-1) / 3;
    }

    if (m[a]==m[b]) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}