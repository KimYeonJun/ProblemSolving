/*
BOJ 2636��: ġ��
���� ���� : BFS

���� Ǯ��
1. �� �Է� ��, ġ���� ������ ī�����Ѵ�.
2. ġ���� ������ 0�� �� ������ BFS �ݺ�
2. BFS�� (0,0)���� �����Ѵ�.(�����ڸ����� ġ� ���� ���� �ʾƼ�)
3. BFS�� ���� , ġ� ������ ������ �ִ� ġ��� �Ǵ��Ͽ� ���� 1�� 0�� �ٲٰ�, ġ�� ���� ����
4. ���⸦ ������ ť�� ����.
5. ġ� ��� ������ ��� ���.
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
int N, M, cheese = 0;
int board[101][101];
bool visit[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> answer_list;
void BFS(int x,int y) {
	queue<pair<int, int>> que;
	que.push({ x,y });
	visit[x][y] = true;
	int cnt = 0;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny])
				continue;
			visit[nx][ny] = true;
			if (board[nx][ny] == 1) {
				//cnt++;
				cheese--;
				board[nx][ny] = 0;
			}
			else {
				que.push({ nx,ny });
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				cheese++;
		}
	}
	int cnt = 0;
	int answer;
	while (cheese > 0) {
		memset(visit, 0, sizeof(visit));
		cnt++;
		answer = cheese;
		BFS(0, 0);
	}
	cout << cnt << endl;
	cout << answer << endl;
	return 0;
}