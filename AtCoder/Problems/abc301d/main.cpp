#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;

    ll N;
    cin >> N;

    ll llS = 0;
    ll e = 1;
    for (int i = S.size()-1; i >= 0; i--) {
        if (S[i] == '1') llS += e;
        e *= 2;
    }
    if (llS > N) {
        cout << -1;
        return;
    }

    vector<ll> pow2;
    ll ee = 1;
    for (int i = 0; i < S.size(); i++) {
        pow2.emplace_back(ee);
        ee *= 2;
    }

    int sindex = 0;
    while (sindex < S.size()) {
        if (S[sindex] == '?') {
            if (llS + pow2[S.size()-1-sindex] <= N) llS += pow2[S.size()-1-sindex];
        }
        sindex++;
    }
    cout << llS;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}