/*
BOJ 1003: �Ǻ���ġ �Լ�

DP�� ����Ͽ� ������ Ǭ��.

Solve1() : �ݺ����� �̿��ؼ� ���� �� ����� DP�� ����ؼ� ���� �ذ�
Solve2() : ��͸� ����ؼ� ž �ٿ� ����� DP�� ����ؼ� ���� �ذ�
           ==>���⼭, N�� 0 ��� Ƚ���� N-1�� 1��� Ƚ���� �����Ƿ�
		   ==>�� N�� 1���Ƚ���� ��͸� ����ؼ� ���Ѵ�.
		   ==>N�� 0ī��Ʈ�� fibonnaci(N-1)�̰�, N�� 1ī��Ʈ�� fibonnaci(N)�̴�.
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