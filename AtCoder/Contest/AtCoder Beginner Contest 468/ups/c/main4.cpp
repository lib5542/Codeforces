#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> visited;
vector<int> P;
vector<int> Q;
int counter;

void dfs(int cur, int N) {
    if (cur == N) {
        if (P < A && A < Q) counter++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            visited[i] = true;

            A.push_back(i+1);
            dfs(cur+1, N);
            A.pop_back();

            visited[i] = false;
        }
    }
}

void solve() {
    cin >> N;

    P.resize(N);
    Q.resize(N);

    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    visited.resize(N, false);

    dfs(0, N);
    cout << counter;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}