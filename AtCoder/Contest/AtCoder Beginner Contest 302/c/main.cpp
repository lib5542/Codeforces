#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<int>> adj(N, vector<int>());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                int wrong_counter = 0;
                for (int k = 0; k < M; k++) {
                    if (S[i][k] != S[j][k]) wrong_counter++;
                }
                if (wrong_counter == 1) adj[i].emplace_back(j);
            }
        }
    }

    vector<bool> visited(N, false);

    auto dfs = [&](auto self, int node, int count) -> bool {
        if (count == N) return true;

        for (const int& neig : adj[node]) {
            if (!visited[neig]) {
                visited[neig] = true;
                if (self(self, neig, count+1)) return true;
                visited[neig] = false;
            }
        }
        return false;
    };

    for (int i = 0; i < N; i++) {
        visited[i] = true;
        if (dfs(dfs, i, 1)) {
            cout << "Yes";
            return;
        }
        visited[i] = false;
    }

    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}