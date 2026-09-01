#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, Q;
    cin >> N >> Q;

    vector<int> P(N);
    vector<int> P_inv(N);

    for (int i = 0; i < N; i++) cin >> P[i];

    for (int i = 0; i < N; i++) {
        P_inv[P[i]-1] = i+1;
    }

    auto swap_element = [&](int& x, int& y) -> void {
        int temp = P[x];
        P[x] = P[y];
        P[y] = temp;
    };

    auto swap_element_inv = [&](int& x, int& y) -> void {
        int temp = P_inv[x];
        P_inv[x] = P_inv[y];
        P_inv[y] = temp;
    };

    int counter = 0;

    while (Q--) {
        int q;
        cin >> q;

        if (q == 1) {
            if (counter % 2 == 0) {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                int x2, y2;
                x2 = P[x]-1;
                y2 = P[y]-1;
                swap_element(x, y);
                swap_element_inv(x2, y2);
            } else {
                int x, y;
                cin >> x >> y;
                x--;
                y--;
                int x2, y2;
                x2 = P_inv[x]-1;
                y2 = P_inv[y]-1;
                swap_element_inv(x, y);
                swap_element(x2, y2);
            }
        } else {
            counter++;
        }
    }
    if (counter % 2 == 0) {
        for (int i = 0; i < N; i++) cout << P[i] << " ";
    } else {
        for (int i = 0; i < N; i++) cout << P_inv[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}