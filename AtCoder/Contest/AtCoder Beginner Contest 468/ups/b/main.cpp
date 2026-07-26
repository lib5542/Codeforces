#include <bits/stdc++.h>

using namespace std;

void solve() {
    int M, D;
    cin >> M >> D;

    string S;
    cin >> S;

    vector<int> dis(M, 1000);

    int last = -1000;
    for (int i = 0; i < M; i++) {
        if (S[i] == 'G') {
            last = i;
            dis[i] = 0;
        } else {
            dis[i] = min(dis[i], i-last);
        }
    }
    last = 1000;
    for (int i = M-1; i >= 0; i--) {
        if (S[i] == 'G') {
            last = i;
            dis[i] = 0;
        } else {
            dis[i] = min(dis[i], last-i);
        }
    }
    int counter = 0;
    for (int i = 0; i < M; i++) {
        if (dis[i] > D) counter++;
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}