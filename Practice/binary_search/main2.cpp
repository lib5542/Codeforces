#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int>& A, int x) {
    int left = 0;
    int right = A.size()-1;
    int res = -1;

    while (left <= right) {
        int mid = left + (right-left)/2;
        if (A[mid] <= x) {
            res = mid;
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return res;
}

int my_upper_bound(vector<int>& A, int x) {
    int left = 0;
    int right = A.size()-1;
    int res = -1;

    while (left <= right) {
        int mid = left + (right-left)/2;
        if (A[mid] > x) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int my_lower_bound(vector<int>& A, int x) {
    int left = 0;
    int right = A.size()-1;
    int res = -1;

    while (left <= right) {
        int mid = left + (right-left)/2;
        if (A[mid] >= x) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {

    vector<int> A = {1, 4, 5, 5, 5, 7, 8, 9};

    int t = binary_search(A, 7);
    cout << t << "\n";

    int t2 = my_upper_bound(A, 5);
    cout << t2 << "\n";

    int t3 = my_lower_bound(A, 5);
    cout << t3;

    return 0;
}