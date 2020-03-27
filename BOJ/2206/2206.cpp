/*
BOJ 2206��: �� �μ��� �̵��ϱ�
���� ���� : �ùķ��̼�(BFS)
���� Ǯ�� : 
			������ ��ٷο� BFS ����. BFS Ž�� ������ �ʹ� �����.
			queue�� ��ǥ,�� �ձ� ��뿩��, �̵� �Ÿ��� ������ �̵��Ѵ�.
			�� ��ǥ�� �湮 �������δ� �� �ձ⸦ ����ϰ� �湮�ߴ���, �� �ձ⸦ ������� �ʰ� �湮�ߴ��� üũ�� ���� 3�����迭�� ���.
			ť�� push �������δ� 
				1. ���� ��ǥ�� ���̰�, �� �ձ⸦ ����ߴ��� -> �������
				2. ���� ��ǥ�� ���̰�, �� �ձ⸦ ��� ���ߴ��� -> �� �ձ⸦ ����ϰ� �湮�ߴٰ� üũ
				3. ���� ��ǥ�� ���� �ƴϰ�,  �� �ձ⸦ ����� ��� -> �� �ձ⸦ ����ϰ� �湮�ߴ��� Ȯ�� 
							-> �� �ձ⸦ ����ϰ� �̹� �湮�� ���̶�� �ִܰŸ��� �ĺ����� �����.
				4. ���� ��ǥ�� ���� �ƴϰ� , �� �ձ⸦ ������� ���� ��� -> �� �ձ⸦ ������� �ʰ� �湮�ߴ��� Ȯ��
							-> �� �ձ⸦ ������� �ʰ� �̹� �湮�ߴ� ���̶�� �ִܰŸ��� �ĺ����� �����.
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct people {
	int x;
	int y;
	int breakWall;
	int dis;
};
int N, M;
int board[1001][1001];
bool visit[1001][1001][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void Input() {
	cin >> N >> M;
	string input;
	for (int i = 1; i <=N; i++) {
		cin >> input;
		for (int j = 1; j <= M; j++) {
			board[i][j] = input[j-1] - '0';
		}
	}
}
int BFS() {
	visit[1][1][0] = true;
	queue<people> que;
	que.push(people{ 1,1,0,1 });
	while (!que.empty()) {
		people cur = que.front();
		if (cur.x == N && cur.y == M)
			return cur.dis;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nb = cur.breakWall;
			int ndis = cur.dis + 1;
			if (nx<1 || nx>N || ny<1 || ny>M)
				continue;
			if (board[nx][ny] == 1 && nb == 0) {
				visit[nx][ny][1] = true;
				que.push(people{ nx,ny,1,ndis });
			}
			else if (board[nx][ny] == 0 && !visit[nx][ny][nb]) {
				visit[nx][ny][nb] = true;
				que.push(people{ nx,ny,nb,ndis });
			}
		}

	}
	return -1;
}
void Solve() {
	Input();
	cout << BFS() << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Solve();
	return 0;
}