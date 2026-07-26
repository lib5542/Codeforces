#include <bits/stdc++.h>

using namespace std;

int H, W;

void dfs(int x, int y, vector<vector<char>>& MAP, vector<vector<bool>>& visited) {

    vector<vector<int>> four_dir = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};
    for (auto& pos : four_dir) {
        int i = pos[0];
        int j = pos[1];
        if (0 <= i && i <= H+1 && 0 <= j && j <= W+1) {
            if (MAP[i][j] == '.' && visited[i][j] == false) {
                visited[i][j] = true;
                dfs(i, j, MAP, visited);
            }
        }
    }
}

void solve() {
    cin >> H >> W;

    vector<vector<char>> MAP(H+2, vector<char>(W+2, '.'));
    vector<vector<bool>> visited(H+2, vector<bool>(W+2, false));

    for (int h = 1; h <= H; h++) {
        string s;
        cin >> s;
        for (int w = 1; w <= W; w++) {
            MAP[h][w] = s[w-1];
        }
    }

    int counter = -1;

    for (int x = 0; x <= H+1; x++) {
        for (int y = 0; y <= W+1; y++) {
            if (MAP[x][y] == '.' && visited[x][y] == false) {
                visited[x][y] = true;
                counter += 1;
                dfs(x, y, MAP, visited);
            }
        }
    }

    cout << counter;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}