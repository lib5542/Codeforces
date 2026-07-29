#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> dep(M, 0);

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        dep[a-1]--;
        dep[b-1]++;
    }

    for (int i = 0; i < M; i++) {
        cout << dep[i] << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    소수 출력 사용 시
    cout << fixed;
    cout.precision(10);
    */

    solve();

    return 0;
}