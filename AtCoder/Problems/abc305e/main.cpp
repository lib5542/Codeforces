#include <bits/stdc++.h>

using namespace std;

struct MyCmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> adj(N+1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> guards;
    vector<int> guard_on_ver(N+1, -1);
    set<int> res;

    for (int i = 0; i < K; i++) {
        int p, h;
        cin >> p >> h;
        guards.emplace(pair(p, h));
        guard_on_ver[p] = h;
    }

    while (!guards.empty()) {
        auto temp = guards.top();
        guards.pop();
        int node = temp.first;
        int health = temp.second;

        res.insert(node);
        guard_on_ver[node] = health;

        health--;

        if (health == -1) continue;

        for (const int& neig : adj[node]) {
            if (guard_on_ver[neig] < health) {
                guards.emplace(pair(neig, health));
                guard_on_ver[neig] = health;
            }
        }
    }

    vector<int> result(res.begin(), res.end());
    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (const int& x : result) cout << x << " ";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}