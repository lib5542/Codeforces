#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    vector<string> code(9, "?????????");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 3 || j == 3) {
                code[i][j] = '.';
                code[8-i][8-j] = '.';
            } else {
                code[i][j] = '#';
                code[8-i][8-j] = '#';
            }
        }
    }

    for (int i = 0; i < N-8; i++) {
        for (int j = 0; j < M-8; j++) {

            bool found = true;

            for (int ci = 0; ci < 9; ci++) {
                for (int cj = 0; cj < 9; cj++) {

                    int curx = i+ci;
                    int cury = j+cj;

                    if (code[ci][cj] == '#' && S[curx][cury] != '#') {
                        found = false;
                        break;
                    }
                    if (code[ci][cj] == '.' && S[curx][cury] != '.') {
                        found = false;
                        break;
                    }

                }
                if (!found) break;
            }
            if (found) {
                cout << i+1 << " " << j+1 << "\n";
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