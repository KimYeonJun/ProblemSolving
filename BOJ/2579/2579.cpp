/*
BOJ 2579번: 계단 오르기

문제 유형 : DP
문제 풀이 : 1층,2층,3층의 경우에는 명확한 값이므로 미리 구하고 4층 이상부터는 점화식을 통해 접근
            N층의 경우 가능한 경우의 수는 2가지이다.
			첫 번째는, N-2층까지의 최댓값 + N층의 값
			두 번째는, N-3층까지의 최댓값 + N-1층의 값 + N층의 값
			2가지 case중 최댓값이 N층의 최댓값이 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int score[301];
int dp[301];
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}
}
void Solution() {
	int result;
	dp[1] = score[1];
	dp[2] = score[1]+score[2];
	dp[3] = max(score[1] + score[3], score[2] + score[3]);
	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}
	cout << dp[N] << endl;
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