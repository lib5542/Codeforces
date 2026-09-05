#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> appear(N+1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        appear[b] = 1;
    }

    int counter = 0;
    int res = 0;

    for (int i = 1; i <= N; i++) {
        if (appear[i] == 0) {
            counter++;
            res = i;
        }
    }
    if (counter == 1) cout << res;
    else cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}