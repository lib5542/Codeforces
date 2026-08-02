#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Answer;

void shift(vector<int>& A) {
	int temp = A[0];
	for (int i = 1; i < A.size(); i++) {
		A[i-1] = A[i];
	}
	A[A.size()-1] = temp;
}

void plusA(vector<int>& A) {
	for (int i = 0; i < A.size(); i++) {
		A[i]++;
		if (A[i] == 10) A[i] = 0;
	}
}

int main(int argc, char** argv) {
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++) {

		Answer = 0;



		int N;
		cin >> N;

		string s;
		cin >> s;

		vector<int> num(N);
		for (int i = 0; i < N; i++) {
			num[i] = s[i]-'0';
		}
		vector<int> minNum(num.begin(), num.end());

		for (int i = 0; i < N; i++) {
			for (int i = 0; i < 10; i++) {
				plusA(num);
				if (minNum > num) minNum = num;
			}
			shift(num);
		}


        

		cout << "Case #" << test_case+1 << endl;
		for (int i = 0; i < N; i++) cout << minNum[i];
		cout << endl;

	}

	return 0;
}