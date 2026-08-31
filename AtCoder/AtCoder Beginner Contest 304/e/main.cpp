#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
vector<vector<int>> adj;
vector<int> arr;

int myFind(int x) {
    if (x == arr[x]) {
        return x;
    } else {
        arr[x] = myFind(arr[x]);
        return arr[x];
    }
}

void myUnion(int x, int y) {
    int X = myFind(x);
    int Y = myFind(y);
    if (x == y) return;
    arr[X] = Y;
}

void dfs(int node) {
    for (const int& neig : adj[node]) {
        if (!visited[neig]) {
            visited[neig] = true;
            myUnion(node, neig);
            dfs(neig);
        }
    }
}

void solve() {
    int N, M;
    cin >> N >> M;

    visited.assign(N+1, false);
    adj.assign(N+1, vector<int>());
    arr.resize(N+1);
    iota(arr.begin()+1, arr.end(), 1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }

    int K;
    cin >> K;

    set<pair<int, int>> ban;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;

        int rootx, rooty;
        rootx = myFind(x);
        rooty = myFind(y);

        ban.insert(pair(rootx, rooty));
        ban.insert(pair(rooty, rootx));
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        if (ban.find(pair(myFind(p), myFind(q))) == ban.end()) cout << "Yes\n";
        else cout << "No\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}