#include <bits/stdc++.h>

using namespace std;

void solve() {
    int Q;
    cin >> Q;

    multiset<int> trees;

    while (Q--) {
        int q, h;
        cin >> q >> h;

        if (q == 1) {
            trees.insert(h);
        } else {
            trees.erase(trees.begin(), trees.upper_bound(h));
        }

        cout << trees.size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}