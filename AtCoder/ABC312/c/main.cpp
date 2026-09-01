#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e9 + 1;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> B(M);
    for (int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll left = 1;
    ll right = INF;

    ll res;

    while (left <= right) {

        ll mid = left + (right-left)/2;

        int seller = upper_bound(A.begin(), A.end(), mid) - A.begin();
        int buyer = M - (lower_bound(B.begin(), B.end(), mid) - B.begin());

        if (seller >= buyer) {
            right = mid - 1;
            res = mid;
        }
        else left = mid + 1;

    }

    cout << res;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}