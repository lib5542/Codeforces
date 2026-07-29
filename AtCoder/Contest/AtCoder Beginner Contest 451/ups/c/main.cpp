#include <bits/stdc++.h>

using namespace std;

void solve() {
    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> heap;

    while (Q--) {
        int q, h;
        cin >> q >> h;

        if (q == 1) heap.push(h);
        else {
            while (!heap.empty() && heap.top() <= h) heap.pop();
        }

        cout << heap.size() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}