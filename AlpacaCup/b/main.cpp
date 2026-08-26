#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = 1e15;

struct Node {
    ll leftDist;
    ll leftIdx;
    ll rightDist;
    ll rightIdx;
    ll myIdx;
};

struct myCmp {
    bool operator()(const Node& a, const Node& b) {
        return a.rightDist > b.rightDist;
    } 
};

void solve() {
    ll N, C;
    cin >> N >> C;

    vector<ll> X(N);
    for (int i = 0; i < N; i++) cin >> X[i];

    // left value, right value, valid
    map<ll, vector<ll>> m;
    for (int i = 1; i < N-1; i++) {
        vector<ll> temp = {X[i]-X[i-1], X[i+1]-X[i], 1};
        m[i] = temp;
    }
    vector<ll> temp = {INF, X[1]-X[0], 1};
    m[0] = temp;
    temp = {X[N-1]-X[N-2], INF, 1};
    m[N-1] = temp;

    priority_queue<Node, vector<Node>, myCmp> pq;
    for (int i = 0; i < N; i++) {
        Node node = {m[i][0], i-1, m[i][1], i+1, i};
        pq.emplace(node);
    }

    ll counter = N;
    while (counter > C) {
        Node node = pq.top();
        pq.pop();

        if (m[node.myIdx][2] == 0) continue;

        m[node.rightIdx][2] = 0;
        node.rightDist += m[node.rightIdx][1];
        node.rightIdx++;
        counter--;

        pq.push(node);
    }

    vector<ll> res;
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        if (!m[node.myIdx][2]) continue;

        res.emplace_back(node.rightDist);

    }

    cout << *min_element(res.begin(), res.end());

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}