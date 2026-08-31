#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N, M, H, K;
    cin >> N >> M >> H >> K;

    string S;
    cin >> S;

    set<pair<ll, ll>> item;
    for (int i = 0; i < M; i++) {
        pair<ll, ll> input;
        cin >> input.first >> input.second;
        item.emplace(input);
    }

    string ans = "Yes";
    pair<ll, ll> cur(0, 0);
    for (int i = 0; i < S.size(); i++) {
        char command = S[i];

        switch (command) {
            case 'U':
            cur.second += 1;
            break;
            case 'D':
            cur.second -= 1;
            break;
            case 'L':
            cur.first -= 1;
            break;
            case 'R':
            cur.first += 1;
            break;
        }

        H -= 1;

        if (H < 0) {
            ans = "No";
            break;
        }

        if (item.find(cur) != item.end() && H < K) {
            H = K;
            item.erase(cur);
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}