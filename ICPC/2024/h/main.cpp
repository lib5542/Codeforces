#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int A, B, C, D, E, F, G, H;
int l, m, d, h;

bool isValid(vector<int>& perm) {
    int a = perm[0];
    int b = perm[1];
    int c = perm[2];
    int e = perm[3];
    int f = perm[4];
    int g = perm[5];
    int i = perm[6];
    int j = perm[7];
    int k = perm[8];

    if (A != a+e+i+l) return false;
    if (B != b+f+j+m) return false;
    if (C != c+g+k) return false;
    if (E != a+b+c+d) return false;
    if (F != e+f+g+h) return false;
    if (G != i+j+k) return false;

    return true;
}

void solve() {
    vector<int> inp(8);
    for (int i = 0; i < 8; i++) cin >> inp[i];
    A = inp[0];
    B = inp[1];
    C = inp[2];
    D = inp[3];
    E = inp[4];
    F = inp[5];
    G = inp[6];
    H = inp[7];

    vector<int> visited(14, 0);

    ll ans = 0;

    // l, m 선택
    for (int i = 1; i <= 13; i++) {
        l = i;
        m = H-i;
        if (m > 13 || m < 1) continue;
        if (l == m) continue;
        visited[l] = 1;
        visited[m] = 1;

        // d, h 선택
        for (int j = 1; j <= 13; j++) {
            d = j;
            h = D-j;
            if (h > 13 || h < 1) continue;
            if (d == h || d == l || d == m || h == l || h == m) continue;
            visited[d] = 1;
            visited[h] = 1;

            vector<int> perm;
            for (int i = 1; i <= 13; i++) {
                if (visited[i] == 0) perm.emplace_back(i);
            }

            do {
                if (isValid(perm)) {
                    ans++;
                }
            } while (next_permutation(perm.begin(), perm.end()));

            visited[d] = 0;
            visited[h] = 0;
        }

        visited[l] = 0;
        visited[m] = 0;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}