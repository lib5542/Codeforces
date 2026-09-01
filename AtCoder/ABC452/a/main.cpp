#include <bits/stdc++.h>

using namespace std;

void solve() {
    int M, D;
    cin >> M >> D;

    if (M == 1 && D == 7) cout << "Yes";
    else if (M == 3 && D == 3) cout << "Yes";
    else if (M == 5 && D == 5) cout << "Yes";
    else if (M == 7 && D == 7) cout << "Yes";
    else if (M == 9 && D == 9) cout << "Yes";
    else cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}