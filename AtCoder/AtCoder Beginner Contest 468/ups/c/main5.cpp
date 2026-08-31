#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Q(N);

    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    vector<int> A;
    vector<bool> visited(N, false);
    int counter = 0;

    auto dfs = [&](auto& self, int cur) -> void {
        if (cur == N) {
            if (P < A && A < Q) counter++;
            return;
        }
        for (int i = 0; i < N; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                A.push_back(i+1);
                self(self, cur+1);
                A.pop_back();
                visited[i] = false;
            }
        }
    };
    dfs(dfs, 0);
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}