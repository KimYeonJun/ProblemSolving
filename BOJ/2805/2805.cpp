/*
BOJ 2805번: 나무 자르기
문제 유형 : 이분 탐색

나무의 수 1 <= N <= 1,000,000
나무 높이  1 <=  H <= 1,000,000,000 (2^30)
시간 복잡도 : O(NlogH) = 1,000,000 * 30 = 30,000,000
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int treeLens[1000001];
void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> treeLens[i];
	}
}
void Solution() {
	sort(treeLens, treeLens + N);
	int l = 0, r = treeLens[N - 1];
	int result = 0;
	while (l <= r) {
		int m = (l + r) / 2;
		long sum = 0;
		for (int i = 0; i < N; i++) {
			if (treeLens[i] - m > 0)
				sum += treeLens[i] - m;
		}
		if (sum >= M) {
			l = m + 1;
			result = max(m, result);
		}
		else {
			r = m - 1;
		}
	}
	cout << result << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}