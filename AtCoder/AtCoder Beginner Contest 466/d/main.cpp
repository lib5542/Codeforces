#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    map<int, int> Rmap;
    map<int, int> Cmap;

    for (int i = 0; i < M; i++) {
        int R, C;
        cin >> R >> C;

        if (Rmap.find(R) != Rmap.end()) {
            int linked_C = Rmap[R];
            Rmap.erase(R);
            Cmap.erase(linked_C);
        }
        if (Cmap.find(C) != Cmap.end()) {
            int linked_R = Cmap[C];
            Cmap.erase(C);
            Rmap.erase(linked_R);
        }
        Rmap.insert({R, C});
        Cmap.insert({C, R});
    }
    cout << Rmap.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}