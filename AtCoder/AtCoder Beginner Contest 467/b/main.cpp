#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int result = 0;

    for (int i = 0; i < N; i++) {
        int A, B;
        string S;
        cin >> A >> B >> S;

        if (S == "keep") {
            result += B-A;
        }

    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}