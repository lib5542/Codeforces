#include <bits/stdc++.h>

using namespace std;

void solve() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> m(H, vector<char>(W, '.'));

    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            m[i][j] = s[j];
        }
    }
    
    int left_top_x, left_top_y;

    bool br = false;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (m[i][j] == '#') {
                left_top_x = j;
                left_top_y = i;
                br = true;
                break;
            }
        }
        if (br) break;
    }

    int left_bot_x, left_bot_y;

    br = false;
    for (int i = H-1; i >= 0; i--) {
        for (int j = 0; j < W; j++) {
            if (m[i][j] == '#') {
                left_bot_x = j;
                left_bot_y = i;
                br = true;
                break;
            }
        }
        if (br) break;
    }

    int right_top_x, right_top_y;

    br = false;
    for (int i = 0; i < H; i++) {
        for (int j = W-1; j >= 0; j--) {
            if (m[i][j] == '#') {
                right_top_x = j;
                right_top_y = i;
                br = true;
                break;
            }
        }
        if (br) break;
    }

    int right_bot_x, right_bot_y;

    br = false;
    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (m[i][j] == '#') {
                right_bot_x = j;
                right_bot_y = i;
                br = true;
                break;
            }
        }
        if (br) break;
    }

    int ans_x = -10;
    int ans_y = -10;

    if (left_bot_x != left_top_x) {
        if (left_bot_x > left_top_x) {
            ans_x = left_bot_x-1;
            ans_y = left_bot_y;
        } else {
            ans_x = left_top_x-1;
            ans_y = left_top_y;
        }
    } else if (right_bot_x != right_top_x) {
        if (right_bot_x > right_top_x) {
            ans_x = right_top_x+1;
            ans_y = right_top_y;
        } else {
            ans_x = right_bot_x+1;
            ans_y = right_bot_y;
        }
    } else {
        for (int i = left_top_y; i <= left_bot_y; i++) {
            for (int j = left_top_x; j <= right_top_x; j++) {
                if (m[i][j] == '.') {
                    ans_x = j;
                    ans_y = i;
                    break;
                }
            }
        }
    }

    cout << ans_y+1 << " " << ans_x+1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}