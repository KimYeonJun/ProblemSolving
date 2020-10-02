/*
BOJ 2668��: ���� ����
���� ���� : ����Ž��, DFS, ����Ŭ

���� Ǯ��
����Ŭ ���� ���� Ȯ���ϴ� ������, N������ 100�̶� ����Ž�� ����.
DFS ���ڷ� ���� ������ �湮�ؾ� �� ������ ������ Ž���Ѵ�.
�湮�ؾ��� ������, �̹� �湮�� ���̰�, �� ������ ���������� ���ٸ� cycle �߻�.
�̹� �湮�� ���� �ƴ϶��, �湮 üũ �ϰ�, ���� ���� �湮.
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
#define MAX 1000001
#define MOD 1000000000
using namespace std;
int N;
int arr[101];
bool visit[101];
vector<int> answer_list;
void DFS(int start, int cur) {
	if (visit[cur]) {
		if (start == cur) {
			answer_list.push_back(start);
		}
	}
	else {
		visit[cur] = true;
		DFS(start, arr[cur]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i == arr[i]) {
			answer++;
		}
	}
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		visit[i] = true;
		DFS(i,arr[i]);
	}
	sort(answer_list.begin(), answer_list.end());
	cout << answer_list.size() << endl;
	for (int i = 0; i < answer_list.size(); i++) {
		cout << answer_list[i] << endl;
	}
	return 0;
}