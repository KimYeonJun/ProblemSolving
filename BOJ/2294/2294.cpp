/*
백준 2294번: 동전2
문제 유형: dp
dp[i]는 dp[i-input[0]], dp[i-input[1]], .... dp[i-input[n]] 단 i-input[n]>0
중 최솟값 +1이 된다.
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