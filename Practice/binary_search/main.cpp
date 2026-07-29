#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int>& A, int x) {
    int left = 0;
    int right = A.size() - 1;
    int ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (A[mid] <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> A = {4};
    int ans = binary_search(A, 4);
    cout << ans;
    return 0;
}