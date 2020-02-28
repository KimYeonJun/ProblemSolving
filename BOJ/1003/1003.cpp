/*
BOJ 1003: 피보나치 함수

DP를 사용하여 문제를 푼다.

Solve1() : 반복문을 이용해서 바텀 업 방식의 DP를 사용해서 문제 해결
Solve2() : 재귀를 사용해서 탑 다운 방식의 DP를 사용해서 문제 해결
           ==>여기서, N의 0 출력 횟수는 N-1의 1출력 횟수와 같으므로
		   ==>각 N의 1출력횟수를 재귀를 사용해서 구한다.
		   ==>N의 0카운트는 fibonnaci(N-1)이고, N의 1카운트는 fibonnaci(N)이다.
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int T;
int N;
int dp[41];
int zero[41];
int one[41];

int fibonacchi(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n < 0) {
		return 1;
	}
	else {
		if (dp[n] != 0)
			return dp[n];
		dp[n] = fibonacchi(n - 1) + fibonacchi(n - 2);
		return dp[n];
	}
	


}
void Solve2() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int zero;
		int one;
		cin >> N;
		zero = fibonacchi(N - 1);
		one = fibonacchi(N);
		cout << zero << " " << one << endl;

	}
}
void Solve() {
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(one, 0, sizeof(one));
		memset(zero, 0, sizeof(zero));
		cin >> N;
		zero[0] = 1;
		one[0] = 0;
		zero[1] = 0;
		one[1] = 1;
		for (int i = 2; i <= N; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
			one[i] = one[i - 1] + one[i - 2];
		}
		cout << zero[N] << " " << one[N] << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve2();

	return 0;
}