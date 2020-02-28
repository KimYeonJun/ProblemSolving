/*
BOJ 1463번: 1로 만들기

DP를 사용해서 문제 해결.
Solution() : 반복문을 사용한 바텀업 방식을 사용한 DP로 문제 해결
             ==> N에서 사용 가능한 연산은 N-1, N/2, N/3 이다.
			 ==> 세 가지 연산들 중 min값 +1이 N의 연산 횟수이다.

Solution2() : 재귀를 사용한 탑다운 방식을 사용한 DP로 문제 해결
              ==> 위와 같음.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1000010];
void Input() {
	cin >> N;
}
int func(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n] != 0)
		return dp[n];
	else {
		dp[n] = func(n-1) + 1;
		if (n % 2 == 0) {
			dp[n] = min(func(n/2)+1, dp[n]);
		}
		if (n % 3 == 0) {
			dp[n] = min(func(n / 3) + 1, dp[n]);
		}
		return dp[n];
	}
}
void Solution2() {
	cout << func(N) << endl;
}
void Solution() {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i]);
		}
	}

	cout << dp[N] << endl;

}
void Solve() {
	Input();
	Solution2();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();

	return 0;
}