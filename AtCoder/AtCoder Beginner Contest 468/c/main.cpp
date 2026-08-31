#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> P(N);
    vector<int> Q(N);

    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    // ups: 비교 위한 수열 백터 생성하는 방법을 모르겠음. 재귀 이용해야 할 듯
    // 123이 주어지면 123 132 213 231 312 321 벡터 만드는 방법 공부
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}