#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x;
    int y;
    char state;
    int d;
    int step;

    vector<char> his;
};

int visited[1000][1000][4];

void solve() {
    int H, W;
    cin >> H >> W;

    queue<Node> q;

    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; i < W; j++) {
            if (S[i][j] == 'S') {
                Node n;
                n.y = i;
                n.x = j;
                n.state = 'S';
                n.d = 0;
                n.step = 0;
                q.emplace(n);
            }
        }
    }

    int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (auto del : delta) {
            int dx = del[0];
            int dy = del[1];

            int new_x = cur.x + dx;
            int new_y = cur.y + dy;

            char state = cur.state;

            int new_d;

            vector<char> history = cur.his;

            if (del[0] == -1) new_d = 3;
            else if (del[0] == 1) new_d = 2;
            else if (del[1] == -1) new_d = 0;
            else if (del[1] == 1) new_d = 1;

            if (0 <= new_x && new_x < W && 0 <= new_y && new_y < H) {
                if (visited[new_y][new_x][new_d] != 1) {
                    if (S[new_y][new_x] != '#') {
                        if ((state == 'o' && cur.d == new_d) || (state == 'x' && cur.d != new_d) || (state == '.') || (state == 'S')) {
                            if (del[0] == -1) history.emplace_back('L');
                            else if (del[0] == 1) history.emplace_back('R');
                            else if (del[1] == -1) history.emplace_back('U');
                            else if (del[1] == 1) history.emplace_back('D');

                            Node n;
                            n.x = new_x;
                            n.y = new_y;

                            q.emplace(n);
                        }
                    }
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}