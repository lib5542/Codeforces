#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, D;
    cin >> N >> D;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];  
    }

    int result = 0;
    int counter = 0;
    for (int i = 0; i < D; i++) {
        bool temp = true;
        for (int j = 0; j < N; j++) {
            if (S[j][i] == 'x') temp = false;
        }
        if (temp) counter++;
        else counter = 0;

        result = max(result, counter);
    }

    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}