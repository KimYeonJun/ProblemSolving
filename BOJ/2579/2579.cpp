/*
BOJ 2579��: ��� ������

���� ���� : DP
���� Ǯ�� : 1��,2��,3���� ��쿡�� ��Ȯ�� ���̹Ƿ� �̸� ���ϰ� 4�� �̻���ʹ� ��ȭ���� ���� ����
            N���� ��� ������ ����� ���� 2�����̴�.
			ù ��°��, N-2�������� �ִ� + N���� ��
			�� ��°��, N-3�������� �ִ� + N-1���� �� + N���� ��
			2���� case�� �ִ��� N���� �ִ��� �ȴ�.
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