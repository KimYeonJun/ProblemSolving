/*
[BOJ] 15659��: ������ �����ֱ� (3)
���� ���� : ��Ʈ��ŷ, ����

���� Ǯ��
1. �ߺ� ������ ����Ͽ� �����ڸ� �����Ѵ�.
2. ���ϱ� �����ڿ� ������ �����ڴ� ���� ����Ͽ� ���ÿ� �ְ�, ���ϱ�� ����� ���߿� ����Ѵ�.

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
#define plus 1000000002
#define minus 1000000003
using namespace std;
int N, idx = 0;
int arr[101];
int cmd[4];
bool visit[101];
vector<int> vec;
int min_val = 1000000001;
int max_val = -1000000001;
void Solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cmd[i];
	}
}
void Calc() {
	vector<int> stk;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0 || vec[i] == 1) {
			if (stk.size() == 0) {
				stk.push_back(arr[i]);
				if (vec[i] == 0) {
					stk.push_back(plus);
				}
				else if (vec[i] == 1)
					stk.push_back(minus);
				stk.push_back(arr[i + 1]);
			}
			else {
				if (vec[i] == 0) {
					stk.push_back(plus);
				}
				else if (vec[i] == 1)
					stk.push_back(minus);
				stk.push_back(arr[i + 1]);
			}
		}
		else {
			if (stk.size() == 0) {
				if (vec[i] == 2) {
					stk.push_back(arr[i] * arr[i + 1]);
				}
				else if (vec[i] == 3) {
					stk.push_back(arr[i] / arr[i + 1]);
				}
			}
			else {
				int tmp = stk[stk.size() - 1];
				stk.pop_back();
				if (vec[i] == 2) {
					stk.push_back(tmp * arr[i + 1]);
				}
				else if (vec[i] == 3) {
					stk.push_back(tmp / arr[i + 1]);
				}
			}
		}
	}
	int result = stk[0];
	for (int i = 1; i < stk.size() - 1; i += 2) {
		int op = stk[i];
		int n = stk[i + 1];
		if (op == plus)
			result += n;
		else if (op == minus)
			result -= n;
	}
	max_val = max(max_val, result);
	min_val = min(min_val, result);
}
void DFS(int cnt) {
	if (cnt == N - 1) {
		Calc();
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cmd[i] == 0)
			continue;
		cmd[i]--;
		vec.push_back(i);
		DFS(cnt + 1);
		vec.pop_back();
		cmd[i]++;

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	DFS(0);
	cout << max_val << endl;
	cout << min_val << endl;
	return 0;
}