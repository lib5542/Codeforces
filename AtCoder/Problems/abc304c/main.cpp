#include <bits/stdc++.h>

using namespace std;

const int MAX = 2005;

void solve() {
    int N, D;
    cin >> N >> D;

    bool infected[MAX] = {false};
    vector<pair<int, int>> pos(N+1);

    for (int i = 1; i <= N; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    infected[1] = true;

    queue<int> infecting_queue;
    infecting_queue.push(1);

    while (!infecting_queue.empty()) {
        int infected_person = infecting_queue.front();
        infecting_queue.pop();

        for (int i = 1; i <= N; i++) {
            if (i == infected_person || infected[i]) continue;
            int inf_x, inf_y;
            inf_x = pos[infected_person].first;
            inf_y = pos[infected_person].second;

            int cur_x, cur_y;
            cur_x = pos[i].first;
            cur_y = pos[i].second;

            int dist = (inf_x-cur_x)*(inf_x-cur_x) + (inf_y-cur_y)*(inf_y-cur_y);
            if (D*D >= dist) {
                infecting_queue.push(i);
                infected[i] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (infected[i]) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}