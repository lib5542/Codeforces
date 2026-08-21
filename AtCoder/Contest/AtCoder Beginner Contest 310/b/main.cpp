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

    int supIdx = 0;
    while (supIdx < N) {
        bool found = true;
        for (int i = 0; i < N; i++) {
            if (i == supIdx) continue;

            if (P[i] < P[supIdx]) {
                supIdx++;
                found = false;
                break;
            }

            if (C[i] == C[supIdx]) {
                if (P[i] == P[supIdx]) {
                    supIdx++;
                    found = false;
                    break;
                }
                bool tobreak = false;
                for (int j = 0; j < C[i]; j++) {
                    if (F[i][j] != F[supIdx][j]) {
                        supIdx++;
                        found = false;
                        tobreak = true;
                        break;
                    }
                }
                if (tobreak) break;
            } else if (C[i] > C[supIdx]) {
                supIdx++;
                found = false;
                break;
            } else {
                int supIdxCounter = 0;
                int wrongCounter = 0;
                bool tobreak = false;
                for (int j = 0; j < C[i]; j++) {
                    if (wrongCounter > 1) {
                        supIdx++;
                        found = false;
                        break;
                    }
                    if (F[i][j] != F[supIdx][j] && wrongCounter == 0) {
                        supIdxCounter++;
                        wrongCounter++;
                    } else if (F[i][j] != F[supIdx][j] && wrongCounter != 0) {
                        supIdx++;
                        tobreak = true;
                        found = false;
                        break;
                    }
                    supIdxCounter++;
                }
                if (tobreak) break;
            }
        }
        if (found) {
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