#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int res = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (i >= N/2) res+=a;
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}