#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, d;

    // 생성자 추가
    Node() : x(0), y(0), d(0) {}
    Node(int x, int y, int d) : x(x), y(y), d(d) {}
};

Node parent[1000][1000][4];
int visited[1000][1000][4];

void solve() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);

    int startX, startY;

    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                startX = j;
                startY = i;
            }
        }
    }

    // direction: 0-up 1:right 2-down 3-left
    queue<Node> q;
    Node s1 = {startX, startY, 0};
    visited[startY][startX][0] = 1;
    Node s2 = {startX, startY, 1};
    visited[startY][startX][1] = 1;
    Node s3 = {startX, startY, 2};
    visited[startY][startX][2] = 1;
    Node s4 = {startX, startY, 3};
    visited[startY][startX][3] = 1;

    q.emplace(s1);
    q.emplace(s2);
    q.emplace(s3);
    q.emplace(s4);

    int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (auto& dir : delta) {
            int dx = dir[0];
            int dy = dir[1];

            int newX = cur.x + dx;
            int newY = cur.y + dy;

            int newD;
            if (dy == -1) newD = 0;
            if (dx == 1) newD = 1;
            if (dy == 1) newD = 2;
            if (dx == -1) newD = 3;

            if (newX < 0 || W <= newX || newY < 0 || H <= newY) continue;
            if (S[newY][newX] == '#') continue;
            if (S[cur.y][cur.x] == 'o' && cur.d != newD) continue;
            if (S[cur.y][cur.x] == 'x' && cur.d == newD) continue;
            if (visited[newY][newX][newD] == 1) continue;
            visited[newY][newX][newD] = 1;

            if (S[newY][newX] == 'G') {
                vector<char> res;
                if (newD == 0) res.emplace_back('U');
                if (newD == 1) res.emplace_back('R');
                if (newD == 2) res.emplace_back('D');
                if (newD == 3) res.emplace_back('L');
                while (S[cur.y][cur.x] != 'S') {
                    if (cur.d == 0) res.emplace_back('U');
                    if (cur.d == 1) res.emplace_back('R');
                    if (cur.d == 2) res.emplace_back('D');
                    if (cur.d == 3) res.emplace_back('L');
                    cur = parent[cur.y][cur.x][cur.d];
                }
                reverse(res.begin(), res.end());
                cout << "Yes\n";
                for (char& c : res) cout << c;
                exit(0);
            }

            q.emplace(newX, newY, newD);
            parent[newY][newX][newD] = cur;
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