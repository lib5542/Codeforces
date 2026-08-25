#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int A, B, C, D, E, F, G, H;
int l, m, d, h;

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

            for (int a = 1; a <= 13; a++) {
                if (visited[a] == 1) continue;
                visited[a] = 1;
                for (int b = 1; b <= 13; b++) {
                    if (visited[b] == 1) continue;
                    visited[b] = 1;
                    for (int c = 1; c <= 13; c++) {
                        if (visited[c] == 1) continue;
                        visited[c] = 1;
                        if (a + b + c + d != E) {
                            visited[c] = 0;
                            continue;
                        }

                        for (int e = 1; e <= 13; e++) {
                            if (visited[e] == 1) continue;
                            visited[e] = 1;

                            for (int ii = 1; ii <= 13; ii++) {
                                if (visited[ii] == 1) continue;;
                                visited[ii] = 1;

                                if (a + e + ii + l != A) {
                                    visited[ii] = 0;
                                    continue;
                                }


                                for (int f = 1; f <= 13; f++) {
                                    if (visited[f] == 1) continue;
                                    visited[f] = 1;

                                    for (int jj = 1; jj <= 13; jj++) {
                                        if (visited[jj] == 1) continue;
                                        visited[jj] = 1;

                                        if (b + f + jj + m != B) {
                                            visited[jj] = 0;
                                            continue;
                                        }

                                        for (int g = 1; g <= 13; g++) {
                                            if (visited[g] == 1) continue;
                                            visited[g] = 1;

                                            if (e + f + g + h != F) {
                                                visited[g] = 0;
                                                continue;
                                            }

                                            for (int k = 1; k <= 13; k++) {
                                                if (visited[k] == 1) continue;
                                                if (c + g + k != C) continue;
                                                if (ii + jj + k != G) continue;

                                                ans++;
                                            }
                                            visited[g] = 0;

                                        }

                                        visited[jj] = 0;

                                    }
                                    visited[f] = 0;

                                }
                                visited[ii] = 0;

                            }
                            visited[e] = 0;

                        }
                        visited[c] = 0;
                    }
                    visited[b] = 0;
                }
                visited[a] = 0;
            }

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