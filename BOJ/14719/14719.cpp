/*
[BOJ] 14719번: 빗물
문제 유형 : 구현

1. 현재 인덱스를 기준으로 왼쪽 값 중 가장 최대값, 오른쪽 값 중 가장 최대값을 구한다.
2. 현재 인덱스가 1번에서 구한 두 최대값보다 작다면, 두 값중 최소값에서 현재 인덱스의 값을 뺀다.
3. 뺀 값이 고여질 빗물의 값이다.
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
int arr[501];
int N, M;
void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
}
void Solution() {
	int answer = 0;
	for (int i = 1; i < M - 1; i++) {
		int l = 0, r = 0;
		for (int j = 0; j < i; j++) {
			l = max(l, arr[j]);
		}
		for (int j = i + 1; j < M; j++) {
			r = max(r, arr[j]);
		}
		if (arr[i] < l && arr[i] < r) {
			answer += min(l, r) - arr[i];
		}
	}
	cout << answer << endl;
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