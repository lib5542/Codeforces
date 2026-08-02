#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Answer;

int main(int argc, char** argv) {
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {

		Answer = 0;



        int N;
        cin >> N;

        vector<int> A(N);
        vector<int> B(N);

        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        vector<int> AA(N);
        vector<int> BB(N);

        for (int i = 0; i < N; i++) {
            if (A[i] > B[i]) {
                AA[i] = A[i];
                BB[i] = B[i];
            } else {
                AA[i] = B[i];
                BB[i] = A[i];
            }
        }

        long long res = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                res += abs(AA[i]-AA[j]);
                res += abs(BB[i]-BB[j]);
            }
        }
        Answer = res;

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;

	}

	return 0;
}