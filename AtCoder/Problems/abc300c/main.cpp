#include <bits/stdc++.h>

using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> C(H, vector<char>(W, '_'));
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            C[i][j] = s[j];
        }
    }
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<int>> pos = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    int minH = 10000;
    int maxH = -1;

    auto dfs = [&](auto& self, int h, int w) -> void {
        for (auto& p : pos) {
            int hh = h+p[0];
            int ww = w+p[1];
            if (0 <= hh && hh < H && 0 <= ww && ww < W) {
                if (visited[hh][ww] == false && C[hh][ww] == '#') {
                    visited[hh][ww] = true;
                    minH = min(minH, hh);
                    maxH = max(maxH, hh);
                    self(self, hh, ww);
                }
            }
        }
    };

    vector<int> res(min(H, W), 0);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j] == false && C[i][j] == '#') {
                minH = 10000;
                maxH = -1;
                dfs(dfs, i, j);
                res[(maxH-minH)/2 -1]++;
            }
        }
    }
    for (int i = 0; i < min(H, W); i++) cout << res[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}