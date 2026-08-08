#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0) cout << "Fizz\n";
        else cout << i << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}