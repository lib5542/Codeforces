#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> P;
vector<int> Q;
vector<int> current;
vector<bool> visited;
int counter = 0;

void backtrack(int depth) {
    if (depth == N) {
        if (P < current && current < Q) {
            counter++;
        }
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            current.push_back(i);

            backtrack(depth+1);

            current.pop_back();
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

    visited.resize(N+1);
    for (int i = 1; i <= N; i++) visited[i] = false;

    backtrack(0);

    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}