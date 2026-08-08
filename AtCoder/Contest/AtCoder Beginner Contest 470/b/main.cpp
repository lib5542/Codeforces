#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> color_counter(N, 0);

    vector<int> C(N);

    int max_color = 0;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        color_counter[C[i]-1]++;
        if (color_counter[C[i]-1] > max_color) max_color++;
    }

    cout << N-max_color;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}