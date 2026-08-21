#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N);
    vector<int> C(N);
    vector<vector<int>> F(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i] >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int f;
            cin >> f;
            F[i].emplace_back(f);
        }
    }

    int supidx = 0;

    while (supidx < N) {
        for (int i = 0; i < N; i++) {
            if (supidx == i) continue;
            if (P[i] < P[supidx]) {
                supidx++;
                break;
            }
            if (C[i] >= C[supidx]) {
                if (P[i] == P[supidx]) {
                    supidx++;
                    break;
                }
            }
            if (C[i] > C[supidx]) {
                supidx++;
                break;
            }
            int supidxFCounter = 0;
            int wrongCounter = 0;
            bool tobreak = false;
            for (int j = 0; j < C[i]; j++) {
                if (F[i][j] != F[supidx][supidxFCounter]) {
                    wrongCounter++;
                    supidxFCounter++;
                }
                if (wrongCounter > 1) {
                    supidx++;
                    tobreak = true;
                    break;
                }
                supidxFCounter++;
            }
            if (tobreak) break;

            cout << "Yes";
            return;
        }
    }
    cout << "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}