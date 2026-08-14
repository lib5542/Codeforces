#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> counter(N+1, 0);
    vector<int> res;

    for (int i = 0; i < 3*N; i++) {
        int a;
        cin >> a;

        counter[a]++;

        if (counter[a] == 2) {
            res.emplace_back(a);
        }

    }
    for (int i = 0; i < N; i++) cout << res[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}