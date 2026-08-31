#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct cmp {
    bool operator()(auto& a, auto& b) const {
        ll left = a[0] * (b[0]+b[1]);
        ll right = b[0]*(a[0]+a[1]);
        if (left == right) return a[2] < b[2];
        else return left > right; 
    }
};

void solve() {
    int N;
    cin >> N;

    vector<vector<ll>> s(N);
    for (int i = 1; i <= N; i++) {
        ll A, B;
        cin >> A >> B;

        s[i-1] = vector<ll>({A, B, i});
    }

    sort(s.begin(), s.end(), cmp());

    for (int i = 0; i < N; i++) cout << s[i][2] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}