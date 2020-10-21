/*
[BOJ] 15658��: ������ �����ֱ� (2)
���� ���� : ��Ʈ��ŷ, ���Ʈ����

�������� ���� �Է¹ް�
��Ʈ��ŷ���� ����Ž���Ͽ� ������ ���Ѵ�.
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
void DFS(int cnt,int sum) {
	if (cnt == N) {
		max_val = max(max_val, sum);
		min_val = min(min_val, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (cmd[i] == 0)
			continue;
		cmd[i]--;
		if (i == 0) {
			DFS(cnt + 1, sum + arr[cnt]);
		}
		else if (i == 1)
			DFS(cnt + 1, sum - arr[cnt]);
		else if (i == 2)
			DFS(cnt + 1, sum * arr[cnt]);
		else
			DFS(cnt + 1, sum / arr[cnt]);
		cmd[i]++;

	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	DFS(1,arr[0]);
	cout << max_val << endl;
	cout << min_val << endl;
	return 0;
}