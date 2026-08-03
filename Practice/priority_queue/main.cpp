#include <bits/stdc++.h>

using namespace std;

int main() {

    priority_queue<int> pq1;
    pq1.emplace(10);
    pq1.emplace(100);
    pq1.emplace(23);
    pq1.emplace(1);

    while (!pq1.empty()) {
        cout << pq1.top() << "\n";
        pq1.pop();
    }

    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.emplace(10);
    pq2.emplace(100);
    pq2.emplace(23);
    pq2.emplace(1);

    while (!pq2.empty()) {
        cout << pq2.top() << "\n";
        pq2.pop();
    }

    auto myCmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        return a.second < b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(myCmp)> pq3(myCmp);
    pq3.emplace(pair<int, int>(20, 40));
    pq3.emplace(pair<int, int>(10, 20));
    pq3.emplace(pair<int, int>(50, 400));
    pq3.emplace(pair<int, int>(90, 60));
    pq3.emplace(pair<int, int>(60, 10));

    while (!pq3.empty()) {
        cout << pq3.top().first << " " << pq3.top().second << "\n";
        pq3.pop();
    }

    return 0;
}