/*
���� 2294��: ����2
���� ����: dp
dp[i]�� dp[i-input[0]], dp[i-input[1]], .... dp[i-input[n]] �� i-input[n]>0
�� �ּڰ� +1�� �ȴ�.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#define endl '\n'
#define INF 987654321
using namespace std;
int dp[100001]= { 0, };
int arr[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		dp[i] = INF;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[arr[i]] = 1;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i - arr[j] < 0)
				continue;
			dp[i] = min(dp[i], dp[i - arr[j]] + 1);

		}
	}
	if (dp[k] == INF)
		cout << "-1" << endl;
	else
		cout << dp[k] << endl;

}