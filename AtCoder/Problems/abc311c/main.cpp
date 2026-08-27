#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> visited;
int start_node;

void dfs(int node) {
    if (visited[A[node]] == 1) {
        start_node = A[node];
        return;
    } else {
        visited[A[node]] = 1;
        dfs(A[node]);
    }
}

void solve() {
    cin >> N;

    A.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    visited.assign(N+1, 0);

    visited[1] = true;
    dfs(1);

    vector<int> ans;
    ans.emplace_back(start_node);

    int cur = start_node;

    while (true) {
        cur = A[cur];
        if (cur == start_node) break;
        ans.emplace_back(cur);
    }
    
    cout << ans.size() << "\n";
    for (auto& x : ans) cout << x << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}