#include <bits/stdc++.h>

using namespace std;

bool isEq(const string& s1, const string& s2) {
    int counter = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) counter++;
    }
    if (counter == 1) return true;
    else return false;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<int> P(N);
    iota(P.begin(), P.end(), 0);

    bool res = true;
    for (int i = 0; i < N-1; i++) {
        if (!isEq(S[P[i]], S[P[i+1]])) {
            res = false;
        }
    }
    if (res) {
        cout << "Yes";
        return;
    }

    vector<int> endP(N);
    for (int i = 0; i < N; i++) endP[i] = N-i-1;

    while (P != endP) {
        res = true;
        next_permutation(P.begin(), P.end());
        for (int i = 0; i < N-1; i++) {
            if (!isEq(S[P[i]], S[P[i+1]])) {
                res = false;
                break;
            }
        }
        if (res) {
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