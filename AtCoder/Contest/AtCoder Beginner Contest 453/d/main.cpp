#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> S;
int visited[1000][1000][4];

int delta[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> res;

const int maxit = 5 * 1e6;

// 0: up, 1: down, 2: right, 3: left
void dfs(int y, int x, int d, int step) {
    if (step > maxit) return;
    visited[y][x][d] = 1;
    char cur = S[y][x];

    if (cur == 'G') {
        for (char& c : res) {
            cout << c;
        }
        exit(0);
    }

    for (auto& del : delta) {
        int new_x = x+del[0];
        int new_y = y+del[1];

        int new_d;
        if (del[0] == -1) new_d = 3;
        else if (del[0] == 1) new_d = 2;
        else if (del[1] == -1) new_d = 0;
        else if (del[1] == 1) new_d = 1;

        if (0 <= new_x && new_x < W && 0 <= new_y && new_y < H) {
            if (visited[new_y][new_x][new_d] != 1) {
                if (S[new_y][new_x] != '#') {
                    if ((cur == 'o' && d == new_d) || (cur == 'x' && d != new_d) || (cur == '.') || (cur == 'S')) {
                        if (del[0] == -1) res.emplace_back('L');
                        else if (del[0] == 1) res.emplace_back('R');
                        else if (del[1] == -1) res.emplace_back('U');
                        else if (del[1] == 1) res.emplace_back('D');
                        dfs(new_y, new_x, new_d, step+1);
                        res.pop_back();
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> H >> W;

    S.resize(H);
    
    int y, x;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                y = i;
                x = j;
            }
        }
    }

    dfs(y, x, 0, 0);
    dfs(y, x, 1, 0);
    dfs(y, x, 2, 0);
    dfs(y, x, 3, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}