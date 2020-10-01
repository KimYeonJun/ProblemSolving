/*
BOJ 1963�� : �Ҽ� ���
���� ���� : �����佺�׳׽��� ü , BFS

���� Ǯ��
1. �����佺�׳׽��� ü�� ����Ͽ� �Ҽ��� �̸� ����
2. BFS�� Ž���Ͽ� �Է¹��� �� �Ҽ��� ��ȯ�� �������� Ȯ��
3. �Է¹��� �Ҽ� A�κ���, �� �ڸ����� ��� ��ȯ�غ� ��, �Ҽ��̰� �湮���� ���� ����� ť�� push.
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
bool sosu[10001];
bool visit[10001];
void initSosu() {
	for (int i = 2; i <= 100; i++) {
		if (sosu[i])
			continue;
		for (int j = i + i; j <= 10000; j += i) {
			sosu[j] = true;
		}
	}
}
int change(int& num, int& index, int& digit) {
	if (index == 0 && digit == 0)
		return -1;
	string tmp = to_string(num);
	tmp[index] = digit+'0';
	return stoi(tmp);
}
int BFS(int A, int B) {
	queue<pair<int,int>> que;
	que.push({ A,0 });
	visit[A] = true;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		int val = cur.first;
		int cnt = cur.second;
		if (val == B)
			return cnt;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				int nxt = change(val, i, j);
				if (nxt == -1)
					continue;
				if (sosu[nxt] || visit[nxt])
					continue;
				visit[nxt] = true;
				que.push({ nxt,cnt + 1 });
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	initSosu();
	int T;
	int A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(visit, 0, sizeof(visit));
		int answer = BFS(A, B);
		if (answer == -1)
			cout << "Impossible" << endl;
		else
			cout << answer << endl;
	}
	

}