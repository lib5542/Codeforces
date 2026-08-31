#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int c = *max_element(a.begin(), a.end());
    if (c < 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}