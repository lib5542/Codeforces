#include <bits/stdc++.h>

using namespace std;

void up(vector<vector<char>>& A) {
    vector<char> temp = A[0];
    for (int i = 1; i < A.size(); i++) {
        A[i-1] = A[i];
    }
    A[A.size()-1] = temp;
}

void right(vector<vector<char>>& A) {
    int w = A[0].size();
    for (int i = 0; i < A.size(); i++) {
        char temp = A[i][w-1];
        for (int j = w-1; j >= 1; j--) {
            A[i][j] = A[i][j-1];
        }
        A[i][0] = temp;
    }
}

bool check(vector<vector<char>>& A, vector<vector<char>>& B) {
    int H = A.size();
    int W = A[0].size();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W, '.'));
    vector<vector<char>> B(H, vector<char>(W, '.'));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> B[i][j];
    }

    bool same = true;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (check(A, B)) {
                cout << "Yes";
                return;
            }
            right(A);
        }
        up(A);
    }

    cout << "No";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}