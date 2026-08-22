#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> visited;
vector<vector<char>> M;
set<int> safe_H;
set<int> safe_W;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int ans = 0;
int H, W, K;

void solve() {
    cin >> H >> W >> K;

    visited.assign(H, vector<int>(W, 0));

    for (int i = 0; i < H; i++) safe_H.emplace(i);
    for (int i = 0; i < W; i++) safe_W.emplace(i);

    M.resize(H);
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            M[i].emplace_back(s[j]);
            if (s[j] == '#') {
                safe_H.erase(i);
                safe_W.erase(j);
            }
        }
    }

    queue<vector<int>> q;
    for (const auto& safe_x : safe_W) {
        for (const auto& safe_y : safe_H) {
            vector<int> n = {safe_y, safe_x, K+1};
            q.push(n);
        }
    }

    while (!q.empty()) {
        vector<int> f = q.front();
        q.pop();

        int safey = f[0];
        int safex = f[1];
        int k = f[2];

        if (k > 0) {
            if (visited[safey][safex] < k) {
                visited[safey][safex] = k;

                for (auto d : dir) {
                    if (0 <= safey+d[0] && safey+d[0] < H && 0 <= safex+d[1] && safex+d[1] < W) {
                        if (M[safey+d[0]][safex+d[1]] == '.') {
                            q.push({safey+d[0], safex+d[1], k-1});
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] != 0) ans++;
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