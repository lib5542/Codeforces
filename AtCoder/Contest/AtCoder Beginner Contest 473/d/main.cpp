#include <bits/stdc++.h>

using namespace std;

int N, K;

vector<int> arr;
vector<vector<int>> result;

void f(int n, int k) {

    if (n == 1) {
        arr.emplace_back(k-n+1);
        result.emplace_back(arr);
        arr.pop_back();
        return;
    }

    int rep = k / n;

    for (int i = rep; i >= 0; i--) {
        arr.emplace_back(i);
        f(n-1, k - (n*i));
        arr.pop_back();
    }
}

void solve() {
    cin >> N >> K;

    f(N, K);

    for (auto& v : result) {
        reverse(v.begin(), v.end());
    }

    sort(result.begin(), result.end());

    for (auto& v : result) {
        for (auto& num : v) cout << num << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}