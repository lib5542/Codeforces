#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, P, Q;
    cin >> N >> P >> Q;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int minD = *min_element(D.begin(), D.end());

    cout << min(P, Q+minD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}