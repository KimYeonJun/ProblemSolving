/*
SWEA 1949�� : ���� ����
���� ���� : �ùķ��̼�, ����Ž��

1. ���� ���� ���츮���� ���������� ��� DFS Ž��.
2. ���� ĭ�� ���� ĭ���� ���� ���̶�� �״�� DFS Ž��.
3. ���� ĭ�� ���� ĭ���� ���� ���� �ƴ϶��
	(1) ���� ��⸦ �̹� ��������� ���� ĭ���� ���� ����
	(2) ���� ��⸦ ������� �ʾҴٸ�, ���� ĭ�� 1~K���� �����鼭 �����ϰ� ���� ��� ��� üũ.

<-- ó�� Ǯ�� -->
ó�� Ǯ�̿��� ���� ������ ������ ��� ĭ�� ���ʴ�� 1~K���� ��Ƽ� DFS�� �Ͽ���.
�� Ǯ�̴� 89ms�� �ٸ� ����麸�� �ð��� �����ɷ���
��α� ���� ��, �ٽ� Ǯ������ 11ms�� ���� �� �־���.

ó�� Ǯ�̿��� ���� �ȱ�Ƶ� �Ǵ� ������ �����鼭 Ž���� �ϴϱ� �ξ� ���� �ð��� �ҿ��

void Solution() {
	for (int i = 0; i < start_point.size(); i++) {
		int x = start_point[i].first;
		int y = start_point[i].second;
		//�ʸ����Ҷ�
		visit[x][y] = true;
		DFS(x,y,1);
		for (int j = 1; j <= K; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (k == x && l == y)
						continue;
					if (board[k][l] - j >= 0) { //�������
						board[k][l] -= j;
						DFS(x,y,1);
						board[k][l] += j;
					}
				}
			}
		}
		visit[x][y] = false;
	}
}
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, result, max_height;
int board[8][8];
int t_board[8][8];
bool visit[8][8];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<pair<int, int>> start_point;
void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			max_height = max(max_height, board[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == max_height)
				start_point.push_back({ i,j });
		}
	}
}
void Initialize() {
	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));
	result = 0;
	max_height = 0;
	start_point.clear();
}
void DFS(int x, int y, int cnt,bool use) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (visit[nx][ny])
			continue;
		if (board[x][y] > board[nx][ny]) {
			visit[nx][ny] = true;
			DFS(nx, ny, cnt + 1, use);
			visit[nx][ny] = false;
		}
		else {
			if (use)
				continue;
			for (int j = 1; j <= K; j++) {
				int nextVal = board[nx][ny] - j;
				if (nextVal >= 0 && board[x][y]>nextVal) {
					board[nx][ny] -= j;
					visit[nx][ny] = true;
					use = true;
					DFS(nx, ny, cnt + 1, use);
					use = false;
					visit[nx][ny] = false;
					board[nx][ny] += j;
				}
			}
		}
	}
	result = max(result, cnt);
}
void Solution() {
	for (int i = 0; i < start_point.size(); i++) {
		int x = start_point[i].first;
		int y = start_point[i].second;
		visit[x][y] = true;
		DFS(x, y, 1,false);
		visit[x][y] = false;
	}
}
void Solve() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " " << result << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}