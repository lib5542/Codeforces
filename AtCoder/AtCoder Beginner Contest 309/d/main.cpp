#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> visited;
vector<int> dist;

void solve() {
    int N1, N2, M;
    cin >> N1 >> N2 >> M;

    adj.resize(N1+N2+1);
    visited.assign(N1+N2+1, 0);
    dist.assign(N1+N2+1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    queue<pair<int, int>> q;
    q.emplace(pair(1, 0));
    visited[1] = 1;
    while (!q.empty()) {
        pair cur = q.front();
        q.pop();

        int node = cur.first;
        int length = cur.second;
        dist[node] = length;

        for (int& neig : adj[node]) {
            if (!visited[neig]) {
                visited[neig] = 1;
                q.emplace(pair(neig, length+1));
            }
        }
    }

    queue<pair<int, int>> q2;
    q2.emplace(pair(N1+N2, 0));
    visited[N1+N2] = 1;
    while (!q2.empty()) {
        pair cur = q2.front();
        q2.pop();

        int node = cur.first;
        int length = cur.second;
        dist[node] = length;

        for (int& neig : adj[node]) {
            if (!visited[neig]) {
                visited[neig] = 1;
                q2.emplace(pair(neig, length+1));
            }
        }
    }

    int p1 = *max_element(dist.begin()+1, dist.begin()+N1+1);
    int p2 = *max_element(dist.begin()+N1+1, dist.end());

    cout << p1+p2+1;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}