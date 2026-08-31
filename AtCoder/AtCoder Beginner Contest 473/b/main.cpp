#include <bits/stdc++.h>

using namespace std;

int arr[101];

void solve() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        arr[a]++;
    }

    int res = 0;

    for (int i = 1; i <= 100; i++) {
        if (arr[i] % 2 == 1) {
            res += i;
        }
    }

    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}