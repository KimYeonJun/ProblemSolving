/*
[BOJ] 9465번: 스티커
문제 유형 : DP

dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
2행에 대한 점화식을 구할 수 있다.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int arr[2][100001];
int dp[2][100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = arr[0][1] + arr[1][0];
		dp[1][1] = arr[0][0] + arr[1][1];
		for (int i = 2; i < N; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		cout << max(dp[0][N - 1], dp[1][N - 1]) << endl;

	}

}